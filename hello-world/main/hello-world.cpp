// This is a preprocessor directive used to include files in our program. During compilation
// this will be replaced with the iostream file contents.
#include <iostream>

// Start of our main function
int main() {

    // std is a namespace, and cout is a predefined object in
    // that namespace with the '<<' operator overloaded in order
    // to print to the screen.

    // Don't worry if that's a bit impenetrable, it's enough to
    // know std::cout is a way of printing to screen, and that
    // std::endl is a newline character
    std::cout << "Hello, World!" << std::endl;

    // Here we return an exit status to show the program has
    // executed successfully    
    return 0;
}