// #include "<std>"
#include "correct_class.h"

CorrectClass::CorrectClass(std::string *string_pointer): _string_pointer(string_pointer) {
    std::cout << "Calling normal constructor" << std::endl;
    _string_pointer = new std::string("A");
}

void CorrectClass::print() {
    std::cout << *_string_pointer << std::endl;
}