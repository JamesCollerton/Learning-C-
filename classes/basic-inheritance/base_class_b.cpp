#include "base_class_b.h"

// Our second simple base class' implementation
BaseClassB::BaseClassB(
        std::string id
    ): m_baseClassBId(id) {}

void BaseClassB::print() {
    std::cout << "Base class B Id " << this->m_baseClassBId << std::endl;
}