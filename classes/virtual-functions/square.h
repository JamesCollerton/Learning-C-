// C++ 11 provides a new specifier override that is very useful to avoid common mistakes while using virtual functions. Note, this only works for virtual, overridden functions.

// Should we make all functions virtual?

// What are the different access modifiers for inheritance?

#include "shape.h"

#pragma once

// This is interesting, we need to declare the inheritance as public in
// order for other code to know about it.
class Square: public Shape {
  
  public:
    void printName() override;
    void printSides();

};