#include "square.h"
#include "shape.h"

int main() {

    // Declare a shape pointer to a square instance
    Square square;
    Shape* shape_pointer_to_square = &square;

    // Virtual function, know's it's a square
    shape_pointer_to_square->printName();

    // Non-virtual functions, doesn't know it's a square
    shape_pointer_to_square->printSides();

    // Note, this only works with pointers
    Shape square_as_shape = Square();

    // This will not know it's a square
    square_as_shape.printName();

    // Note, we can do the same thing with constructors and destructors.

    return 0;
}