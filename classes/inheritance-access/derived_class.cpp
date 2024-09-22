#include "derived_class.h"

void DerivedClass::printPublic() {
    std::cout << m_public << std::endl;
}

void DerivedClass::printPrivate() {
    std::cout << "Can't access m_private!" << std::endl;
}

void DerivedClass::printProtected() {
    std::cout << m_protected << std::endl;
}