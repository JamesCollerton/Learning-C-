#include "http_client.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

HttpClient::HttpClient() {
    // Initialize HTTP client
}

HttpClient::~HttpClient() {
    // Cleanup
}

std::optional<ParsedUrl> HttpClient::parseUrl(const std::string& url) {
    ParsedUrl parsed;
    parsed.port = 80; // Default HTTP port
    parsed.path = "/"; // Default path
    
    // Find protocol
    size_t protocolPos = url.find("://");
    if (protocolPos == std::string::npos || protocolPos == 0) {
        return std::nullopt; // Invalid URL - missing protocol or protocol at start
    }
    
    // Check that protocol is valid (http or https)
    std::string protocol = url.substr(0, protocolPos);
    if (protocol != "http" && protocol != "https") {
        return std::nullopt; // Invalid protocol
    }
    
    std::string afterProtocol = url.substr(protocolPos + 3);
    
    if (afterProtocol.empty()) {
        return std::nullopt; // Invalid URL - missing hostname
    }
    
    // Find path
    size_t pathPos = afterProtocol.find('/');
    if (pathPos != std::string::npos) {
        parsed.path = afterProtocol.substr(pathPos);
        afterProtocol = afterProtocol.substr(0, pathPos);
    }
    
    // Find port
    size_t portPos = afterProtocol.find(':');
    if (portPos != std::string::npos) {
        parsed.host = afterProtocol.substr(0, portPos);
        if (parsed.host.empty()) {
            return std::nullopt; // Invalid URL - empty hostname
        }
        std::string portStr = afterProtocol.substr(portPos + 1);
        try {
            parsed.port = std::stoi(portStr);
            if (parsed.port <= 0 || parsed.port > 65535) {
                return std::nullopt; // Invalid port number
            }
        } catch (const std::exception&) {
            return std::nullopt; // Invalid port number
        }
    } else {
        parsed.host = afterProtocol;
        if (parsed.host.empty()) {
            return std::nullopt; // Invalid URL - missing hostname
        }
    }
    
    return parsed;
}

// OSI Model: This method operates primarily at the Transport Layer (Layer 4) and Network Layer (Layer 3).
// - Network Layer (L3): getaddrinfo() performs DNS resolution, converting hostnames to IP addresses
//   (IPv4/IPv6). This is a network-layer concern as it determines the routing path to the destination.
// - Transport Layer (L4): socket() creates a TCP (SOCK_STREAM) endpoint, and connect() establishes
//   a reliable, connection-oriented transport session. TCP handles segmentation, flow control, and
//   error recovery at this layer.
// - Lower layers (Physical L1, Data Link L2) are abstracted away by the OS kernel and network stack.
// - Upper layers (Session L5, Presentation L6, Application L7) are handled by the HTTP protocol implementation.
int HttpClient::connectToHost(const std::string& host, int port) {
    // Prepare the addrinfo "hints" structure for getaddrinfo().
    // This is a POSIX C struct with no default initialization, so we must
    // explicitly zero it to ensure all unspecified fields are set to 0.
    // Zero values mean "use default / don't care" according to the API contract.
    // We then fill in only the fields we care about: allow either IPv4 or IPv6
    // addresses, and request a TCP (stream) socket.

    // 'result' is a pointer that will receive the head of a linked list
    // allocated by getaddrinfo(). We pass &result so getaddrinfo can
    // write the pointer back. 'rp' is used to iterate through this list
    // to try each returned address until a connection succeeds.
    struct addrinfo hints, *result, *rp;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;    // Allow IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP socket
    
    std::string portStr = std::to_string(port);
    // Resolve the hostname and port into one or more socket-ready addresses.
    // getaddrinfo() is a POSIX C API (not part of the C++ standard library),
    // so it uses C-style structs, pointers, and explicit initialization.
    // It translates human-readable names (e.g. "example.com", "80") into a
    // linked list of addrinfo structures that can be passed directly to
    // socket() and connect(). We try each result until a connection succeeds.
    int status = getaddrinfo(host.c_str(), portStr.c_str(), &hints, &result);
    if (status != 0) {
        std::cerr << "getaddrinfo error: " << gai_strerror(status) << std::endl;
        return -1;
    }
    
    // Socket: A socket is a file descriptor (integer) that represents an endpoint for network communication.
    // It's created by the socket() system call and acts as an interface between the application and the
    // OS network stack. The file descriptor (sockfd) is used by the OS to identify this specific socket
    // for operations like connect(), send(), recv(), and close(). In this context, it's a TCP socket
    // (SOCK_STREAM), which provides a reliable, bidirectional byte stream connection. The value -1
    // indicates an invalid/uninitialized socket, which is the standard error return value from socket()
    // and other POSIX socket functions.

    // Try each address until we successfully connect
    int sockfd = -1;
    for (rp = result; rp != nullptr; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        
        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1) {
            break; // Success
        }
        
        close(sockfd);
        sockfd = -1;
    }
    
    freeaddrinfo(result);
    
    if (sockfd == -1) {
        std::cerr << "Could not connect to " << host << ":" << port << std::endl;
        return -1;
    }
    
    return sockfd;
}

// sendRequest: Constructs and sends an HTTP request over the established TCP socket connection.
// This method operates at the Application Layer (OSI Layer 7), implementing the HTTP protocol.
// It builds a complete HTTP request message consisting of:
// 1. Request line: Method (GET/POST), path, and HTTP version (e.g., "GET /path HTTP/1.1\r\n")
// 2. Headers: Required headers like Host, Connection, and optional Content-Length/Content-Type for POST
// 3. Body: Optional request body (for POST requests with data)
// The request is formatted as a text string following HTTP/1.1 specification, then sent over the
// socket using the send() system call. The send() function operates at the Transport Layer (Layer 4),
// writing the bytes to the TCP connection. Returns true on successful transmission, false on error.
bool HttpClient::sendRequest(int sockfd, const std::string& method,
                            const ParsedUrl& parsedUrl, const std::string& body) {
    std::ostringstream request;
    
    // Request line
    request << method << " " << parsedUrl.path << " HTTP/1.1\r\n";
    
    // Headers
    request << "Host: " << parsedUrl.host;
    if (parsedUrl.port != 80) {
        request << ":" << parsedUrl.port;
    }
    request << "\r\n";
    
    request << "Connection: close\r\n";
    
    if (!body.empty()) {
        request << "Content-Length: " << body.length() << "\r\n";
        request << "Content-Type: application/x-www-form-urlencoded\r\n";
    }
    
    // End of headers
    request << "\r\n";
    
    // Body (for POST)
    if (!body.empty()) {
        request << body;
    }
    
    std::string requestStr = request.str();
    ssize_t sent = send(sockfd, requestStr.c_str(), requestStr.length(), 0);
    
    if (sent == -1) {
        std::cerr << "Error sending request" << std::endl;
        return false;
    }
    
    return true;
}

std::string HttpClient::receiveResponse(int sockfd) {
    std::string response;
    char buffer[4096];
    
    while (true) {
        ssize_t received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (received == -1) {
            std::cerr << "Error receiving data" << std::endl;
            break;
        }
        if (received == 0) {
            break; // Connection closed
        }
        
        buffer[received] = '\0';
        response += buffer;
    }
    
    return response;
}

std::string HttpClient::extractBody(const std::string& response) {
    // Find the end of headers (double CRLF)
    size_t headerEnd = response.find("\r\n\r\n");
    if (headerEnd == std::string::npos) {
        return ""; // No body found
    }
    
    // Extract body (everything after headers)
    return response.substr(headerEnd + 4);
}

std::string HttpClient::get(const std::string& url) {
    auto parsedUrl = parseUrl(url);
    if (!parsedUrl.has_value()) {
        std::cerr << "Invalid URL: " << url << std::endl;
        return "";
    }
    
    int sockfd = connectToHost(parsedUrl->host, parsedUrl->port);
    if (sockfd == -1) {
        return "";
    }
    
    if (!sendRequest(sockfd, "GET", *parsedUrl)) {
        close(sockfd);
        return "";
    }
    
    std::string response = receiveResponse(sockfd);
    close(sockfd);
    
    return extractBody(response);
}

std::string HttpClient::post(const std::string& url, const std::string& data) {
    auto parsedUrl = parseUrl(url);
    if (!parsedUrl.has_value()) {
        std::cerr << "Invalid URL: " << url << std::endl;
        return "";
    }
    
    int sockfd = connectToHost(parsedUrl->host, parsedUrl->port);
    if (sockfd == -1) {
        return "";
    }
    
    if (!sendRequest(sockfd, "POST", *parsedUrl, data)) {
        close(sockfd);
        return "";
    }
    
    std::string response = receiveResponse(sockfd);
    close(sockfd);
    
    return extractBody(response);
}

