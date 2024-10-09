#include "shape.h"

#pragma once

class Square: public Shape {
  
  public:
    // Here we declare our intent to override the
    // virtual function
    void printName() override;
    void printSides();

};