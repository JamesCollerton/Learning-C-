// #include "<std>"
#include "correct_class.h"

CorrectClass::CorrectClass(std::string str): _string_pointer(new std::string(str)) {
    std::cout << "Calling normal constructor" << std::endl;
}

CorrectClass::CorrectClass(CorrectClass& correct_class): _string_pointer(new std::string) {
    std::cout << "Calling copy constructor" << std::endl;
    _string_pointer = new std::string(*correct_class._string_pointer);
    // _string_pointer = correct_class._string_pointer;
}

// CorrectClass::CorrectClass(CorrectClass&& correct_class) {
//     std::cout << "Calling move constructor" << std::endl;
// }

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