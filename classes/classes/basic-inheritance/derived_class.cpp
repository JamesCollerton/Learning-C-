#include "derived_class.h"

// Here we implement the constructor. Notice how it initalises 
// it's base classes in the member initializer list.
DerivedClass::DerivedClass(std::string name): 
    BaseClassA("Base class A name", 100, "Base class A Id"),
    BaseClassB("Base class B Id"),
    m_derivedClassName(name){}

// Here we implement the print function. It calls the print functions
// in both subclasses, then prints the value stored in the class itself.

// Note, we could access some of the members of Base Class A (the protected
// ones), but if we tried to access the private ones we would receive an
// error.
void DerivedClass::print() {
    BaseClassA::print();
    BaseClassB::print();
    std::cout << "Derived class name " << this->m_derivedClassName << std::endl;
}