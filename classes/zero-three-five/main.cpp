#include <iostream>
#include "correct_class.h"

int main() {

    std::string cc_string = "Correct class";
    std::string *cc_string_pointer = &cc_string;
    CorrectClass correct_class(cc_string_pointer);
    
    std::string cc_string_2 = "Correct class 2";
    cc_string_pointer = &cc_string_2;

    correct_class.print();

    return 0;
}

