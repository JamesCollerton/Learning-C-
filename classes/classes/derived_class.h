#include <iostream>
#include "base_class_a.h"

#pragma once

class DerivedClass: BaseClassA {
  
  private:
    std::string m_derivedClassName;
  
  public:

    DerivedClass(std::string name);

    void print();
};