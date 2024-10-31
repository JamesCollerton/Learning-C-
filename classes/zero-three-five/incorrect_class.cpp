#include "incorrect_class.h"

IncorrectClass::IncorrectClass(std::string str): _string_pointer(new std::string(str)) {
    std::cout << "Calling normal constructor" << std::endl;
}

void IncorrectClass::print() {
    std::cout << *_string_pointer << std::endl;
}