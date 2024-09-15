#include "square.h"
#include "shape.h"

// TODO: Is this runtime polymorphism?

// Virtual functions are used to achieve runtime polymorphism. In
// the example below 'Square' inherits from 'Shape'. A lot of the time 
// we want to assign square to a Shape variable to increase flexibility.
// However, when we call methods on the object we want to execute those
// assigned to square. In order to do this we need to declare any methods
// in the base class as virtual.

// TODO: Pros and cons of virtual functions.

int main() {

    Shape square_as_shape = Square();
    Square square_as_square = Square();

    // We're expecting this to print 'Square', 'Square'
    square_as_shape.printName();
    square_as_square.printName();

    // We're expecting this to print 'Unknown', '4'
    square_as_shape.printSides();
    square_as_square.printSides();

    // If the virtual function is redefined in the derived class, the 
    // function in the derived class is executed even if it is called 
    // using a pointer of the base class object pointing to a derived 
    // class object. In such a case, the function is said to be overridden.

    // When you refer to a derived class object using a pointer or a 
    // reference to the base class, you can call a virtual function 
    // for that object and execute the derived class’s version of the method.

    // We may also need to do this. Does this only work with pointers?
    Square square;
    Shape* shape_pointer_to_square = &square;

    shape_pointer_to_square->printName();
    shape_pointer_to_square->printSides();

    // Note, we can do the same thing with constructors and destructors.

    return 0;
}

