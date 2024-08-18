#include <iostream>

#pragma once

// Protected access modifier
// Multiple inheritance

class BaseClassA {
  
  protected:
    std::string m_baseClassAName;
    int m_baseClassAVal;
    
    std::string getBaseClassAId();

  private:
    std::string m_baseClassAId;

  public:

    BaseClassA(std::string name, int val, std::string id);

    void print();
};