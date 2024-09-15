#include <iostream>

#pragma once

// Here we have another simple base class, used
// only to demonstrate multiple inheritance.
class BaseClassB {

  private:
    std::string m_baseClassBId;

  public:

    BaseClassB(std::string id);

    void print();
};