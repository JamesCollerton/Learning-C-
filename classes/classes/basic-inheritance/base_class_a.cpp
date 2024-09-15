#include "base_class_a.h"

// Here we have simple implementations of the class defined
// previously.
BaseClassA::BaseClassA(
    std::string name, 
    int val, 
    std::string id
    ): m_baseClassAName(name), m_baseClassAVal(val), m_baseClassAId(id) {}

void BaseClassA::print() {
    std::cout << "Base class A Name " << this->m_baseClassAName << std::endl;
    std::cout << "Base class A Val " << this->m_baseClassAVal << std::endl;
    std::cout << "Base class A Id " << this->m_baseClassAId << std::endl;
}