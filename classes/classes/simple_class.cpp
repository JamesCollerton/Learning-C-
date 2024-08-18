#include "simple_class.h"

// This is the complementary implementation
// for the header class declarations.

// This is the constructor. It uses a 'member initializer
// list', which is a nice wrapper to prevent us having to
// manually assign them (e.g. this->name = name).
SimpleClass::SimpleClass(std::string name, int val): m_name(name), m_val(val) {
    std::cout << "Constructing simple object" << std::endl;
}

// Here we define the destructor. When the object is destroyed we
// will see the below message printed to screen.
SimpleClass::~SimpleClass() {
    std::cout << "Destructing simple object" << std::endl;
}

// This is where we print the object to screen.
void SimpleClass::print() {
    std::cout << "Name " << this->m_name << std::endl;
    std::cout << "Val " << this->m_val << std::endl;
}