#include "square.h"
#include "shape.h"

// Virtual functions are used when we want to execute a derived classes'
// method at runtime, even when we have programmed to the derived classes'
// interface. Admittedly, this is a bit confusing, so let's expand with an
// example below.

int main() {

    // Declare a shape pointer to a square instance. Square inherits from
    // shape, so this is fine.
    Square square;
    Shape* shape_pointer_to_square = &square;

    // printName is a virtual function, this means it knows it's being called
    // on a square object, so will print that it's a square.
    shape_pointer_to_square->printName();

    // printSides is a non-virtual function, so doesn't know it's being called on
    // a square object, and instead reverts to the Shape implementation.
    shape_pointer_to_square->printSides();

    // However, this only works with pointers
    Shape square_as_shape = Square();

    // This will not know it's a square
    square_as_shape.printName();

    // Note, we can do the same thing with constructors and destructors.

    return 0;
}