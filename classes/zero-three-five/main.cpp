#include <iostream>
#include "correct_class.h"

int main() {

    std::string cc_string = "Correct class";
    CorrectClass correct_class(&cc_string);
    correct_class.print();

    return 0;
}

