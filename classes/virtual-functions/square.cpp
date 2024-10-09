#include "square.h"

// This overrides the virtual function, allowing for runtime
// polymorphism
void Square::printName() {
    std::cout << "I am a square." << std::endl;
}

// Overidding a non-virtual function
void Square::printSides() {
    std::cout << "I have four sides!" << std::endl;
}