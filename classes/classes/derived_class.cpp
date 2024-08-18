#include "derived_class.h"

DerivedClass::DerivedClass(std::string name): 
    BaseClassA("Base class A name", 100, "Base class A Id"), 
    m_derivedClassName(name){}

void DerivedClass::print() {
    BaseClassA::print();
    std::cout << "Derived class name " << this->m_derivedClassName << std::endl;
}