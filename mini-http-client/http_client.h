#pragma once

#include <string>

class HttpClient {
public:
    HttpClient();
    ~HttpClient();
    
    // Perform a GET request
    std::string get(const std::string& url);
    
    // Perform a POST request
    std::string post(const std::string& url, const std::string& data);
    
private:
    // Add your private members here
};

