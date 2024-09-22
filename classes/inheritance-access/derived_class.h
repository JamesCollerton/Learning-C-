#include <iostream>
#include "base_class_a.h"

#pragma once

class DerivedClass: public BaseClassA {
    
  public:

    DerivedClass() {}

    void printPublic();
    
    void printPrivate();

    void printProtected();
};