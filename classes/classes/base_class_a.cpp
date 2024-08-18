#include "base_class_a.h"

BaseClassA::BaseClassA(
    std::string name, 
    int val, std::string id
    ): m_baseClassAName(name), m_baseClassAVal(val), m_baseClassAId(id) {}

void BaseClassA::print() {
    std::cout << "Name " << this->m_baseClassAName << std::endl;
    std::cout << "Val " << this->m_baseClassAVal << std::endl;
    std::cout << "Id " << this->m_baseClassAId << std::endl;
}