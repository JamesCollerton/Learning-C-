#include <iostream>
#include "http_client.h"

int main() {
    std::cout << "Mini HTTP Client" << std::endl;
    std::cout << "=================" << std::endl;
    
    HttpClient client;
    
    // Test GET request to a simple URL
    std::cout << "\nMaking GET request to http://example.com..." << std::endl;
    std::string response = client.get("http://example.com");
    
    if (!response.empty()) {
        std::cout << "\nResponse received (" << response.length() << " bytes):" << std::endl;
        std::cout << "---" << std::endl;
        // Print first 500 characters to avoid overwhelming output
        if (response.length() > 500) {
            std::cout << response.substr(0, 500) << std::endl;
            std::cout << "... (truncated, total " << response.length() << " bytes)" << std::endl;
        } else {
            std::cout << response << std::endl;
        }
        std::cout << "---" << std::endl;
    } else {
        std::cout << "Failed to receive response or response was empty." << std::endl;
    }
    
    return 0;
}

