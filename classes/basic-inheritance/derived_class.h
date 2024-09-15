#include <iostream>
#include "base_class_a.h"
#include "base_class_b.h"

#pragma once

// This is our derived class. It extends two base classes,
// as in C++ we can have multiple inheritance.
class DerivedClass: BaseClassA, BaseClassB {
  
  private:
    std::string m_derivedClassName;
  
  public:

    DerivedClass(std::string name);

    void print();
};