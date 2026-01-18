#pragma once

#include <string>
#include <optional>

struct ParsedUrl {
    std::string host;
    int port;
    std::string path;
};

class HttpClient {
public:
    HttpClient();
    ~HttpClient();
    
    // Perform a GET request
    std::string get(const std::string& url);
    
    // Perform a POST request
    std::string post(const std::string& url, const std::string& data);
    
private:
    // Parse URL into components, returns nullopt on failure
    std::optional<ParsedUrl> parseUrl(const std::string& url);
    
    // Create socket and connect to host
    int connectToHost(const std::string& host, int port);
    
    // Send HTTP request over socket
    bool sendRequest(int sockfd, const std::string& method, 
                    const ParsedUrl& parsedUrl, const std::string& body = "");
    
    // Receive and parse HTTP response
    std::string receiveResponse(int sockfd);
    
    // Extract body from HTTP response
    std::string extractBody(const std::string& response);
};

