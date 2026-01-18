#include "http_client.h"
#include <cassert>
#include <iostream>

// Helper function to test URL parsing
void testParseUrl(const std::string& url, bool shouldSucceed, 
                  const std::string& expectedHost = "", 
                  int expectedPort = 80, 
                  const std::string& expectedPath = "/") {
    HttpClient client;
    auto parsed = client.parseUrl(url);
    
    if (shouldSucceed) {
        assert(parsed.has_value() && "URL should parse successfully");
        assert(parsed->host == expectedHost && "Host should match");
        assert(parsed->port == expectedPort && "Port should match");
        assert(parsed->path == expectedPath && "Path should match");
        std::cout << "✓ Test passed: " << url << std::endl;
    } else {
        assert(!parsed.has_value() && "URL should fail to parse");
        std::cout << "✓ Test passed (expected failure): " << url << std::endl;
    }
}

int main() {
    std::cout << "Running HTTP Client Tests" << std::endl;
    std::cout << "=========================" << std::endl;
    
    // Test valid URLs
    std::cout << "\nTesting valid URLs:" << std::endl;
    testParseUrl("http://example.com", true, "example.com", 80, "/");
    testParseUrl("http://example.com/", true, "example.com", 80, "/");
    testParseUrl("http://example.com/path", true, "example.com", 80, "/path");
    testParseUrl("http://example.com/path/to/resource", true, "example.com", 80, "/path/to/resource");
    testParseUrl("http://example.com:8080", true, "example.com", 8080, "/");
    testParseUrl("http://example.com:8080/path", true, "example.com", 8080, "/path");
    testParseUrl("http://subdomain.example.com", true, "subdomain.example.com", 80, "/");
    testParseUrl("http://localhost:3000/api", true, "localhost", 3000, "/api");
    
    // Test invalid URLs
    std::cout << "\nTesting invalid URLs:" << std::endl;
    testParseUrl("", false);
    testParseUrl("example.com", false);  // Missing protocol
    testParseUrl("://example.com", false);  // Missing protocol name
    testParseUrl("http://", false);  // Missing hostname
    testParseUrl("http://:8080", false);  // Empty hostname with port
    testParseUrl("http://example.com:0", false);  // Invalid port (too low)
    testParseUrl("http://example.com:65536", false);  // Invalid port (too high)
    testParseUrl("http://example.com:abc", false);  // Invalid port (not a number)
    testParseUrl("http://example.com:-1", false);  // Invalid port (negative)
    
    std::cout << "\nAll tests passed!" << std::endl;
    return 0;
}

