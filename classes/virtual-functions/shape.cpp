#include "shape.h"

// Virtual function, bound at runtime
void Shape::printName() {
    std::cout << "I am just a generic shape." << std::endl;
}

// Non-virtual function, bound at compile time
void Shape::printSides() {
    std::cout << "I don't know how many sides I have!" << std::endl;
}