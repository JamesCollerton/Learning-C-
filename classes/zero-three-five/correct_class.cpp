#include "correct_class.h"

CorrectClass::CorrectClass(std::string str): _string_pointer(new std::string(str)) {
    std::cout << "Calling normal constructor" << std::endl;
}

CorrectClass::CorrectClass(CorrectClass& correct_class): CorrectClass(*correct_class._string_pointer) {
    std::cout << "Calling copy constructor" << std::endl;
}

CorrectClass::CorrectClass(CorrectClass&& correct_class): _string_pointer(correct_class._string_pointer) {
    std::cout << "Calling move constructor" << std::endl;
    correct_class._string_pointer = nullptr;
}

CorrectClass& CorrectClass::operator=(const CorrectClass &other) {
    std::cout << "Calling copy assignment" << std::endl;
    _string_pointer = new std::string(*other.m_value);
    return *this;
}

CorrectClass& CorrectClass::operator=(CorrectClass &&other) {
    std::cout << "Calling move assignment" << std::endl;

    if(this != &other){
        m_value = other.m_value;
        other.m_value = nullptr;
    }
    return *this;
}

CorrectClass::~CorrectClass() {
    std::cout << "Calling destructor" << std::endl;
    if(NULL != _string_pointer) {
        delete _string_pointer;
        _string_pointer = NULL;
    }
}

void CorrectClass::print() {
    std::cout << *_string_pointer << std::endl;
}