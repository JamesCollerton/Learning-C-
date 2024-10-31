#include "correct_class.h"
#include "incorrect_class.h"

// The rule of 0 / 3 / 5

// The rule of 0: Try and avoid defining destructors, copy constructors, copy assignment, 
// move constructors, move assignment. This is in the C++ core guidelines: 
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-zero

// The rule of 5: If you need one of them, you probably need them all of them.

// The rule of 3: From days before move constructor and move assignment (so you only 
// needed the copy functions).

// This mainly applies when you have a user-defined type responsible for managing a 
// resource where the handle doesn't destroy the object, or make deep copies.

// You need the user-defined constructor and destructor in order to allocate and free 
// memory for the resource your class owns. 

// You need the copy constructor and assignment as under-the-hood, C++ often copies or 
// copy assigns objects (e.g. when you do a = b), and if you don't define the correct 
// way to do this, then it may make unexpected shallow copies.

// If you define custom copy constructor and assignment you also need custom move constructors 
// and assignment. An interesting discussion of why this is is here. 
// https://stackoverflow.com/questions/11255027/why-user-defined-move-constructor-disables-the-implicit-copy-constructor

// Helpful
// https://www.codementor.io/@sandesh87/the-rule-of-five-in-c-1pdgpzb04f
// https://medium.com/@weidagang/modern-c-to-rule-of-zero-or-five-2a3dded258b1
// https://www.scaler.com/topics/cpp-char/


int main() {

    CorrectClass correct_class("Correct Class");
    CorrectClass correct_class_2 = correct_class;
    
    correct_class.print();

    IncorrectClass incorrect_class("Correct Class");
    IncorrectClass incorrect_class_2 = incorrect_class;

    incorrect_class.print();

    return 0;
}

