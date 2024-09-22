#include <iostream>

#include "derived_class.h"

int main() {

    auto derivedObject = DerivedClass();
    derivedObject.printPublic();
    derivedObject.printPrivate();
    derivedObject.printProtected();

    std::cout << derivedObject.m_public << std::endl;
    std::cout << derivedObject.m_protected << std::endl;

    return 0;
}

