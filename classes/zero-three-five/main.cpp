#include <iostream>
#include "correct_class.h"

int main() {

    CorrectClass correct_class("Correct Class");
    CorrectClass correct_class_2 = correct_class;
    
    correct_class.print();

    return 0;
}

