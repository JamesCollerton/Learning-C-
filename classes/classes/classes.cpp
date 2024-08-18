#include <iostream>

// We include the header, but not the implementation.
#include "simple_class.h"
#include "derived_class.h"

int main() {

    // Create our object and print it to the screen.
    // auto simpleObject = SimpleClass("Name", 100);
    // simpleObject.print();

    // This will output:
    //  Constructing simple object
    //  Name Name
    //  Val 100
    //  Destructing simple object

    auto derivedObject = DerivedClass("Derived class name");
    derivedObject.print();

    return 0;
}

