#include <iostream>

// This is so we only include the contents of
// this file once. If multiple other files all
// tried to include simple_object.h, then we would
// get multiple definitions of the same thing.

// #pragma once is a bit controversial as it doesn't
// work with all compilers, but is used to make sure
// the header file is only included once per compilation.
// If we have two files which both include the same header
// then the compiler may complain, as it sees the same
// thing being defined twice (for example, I can't say
// int x = 5, int x = 3 ).
#pragma once

// Here we expose the API of our simple class.
class SimpleClass {
  
  // These are all the private parts of the class. In
  // this particular example we have two member variables,
  // a name and a value.
  private:
    std::string m_name;
    int m_val;

  // These are all the publicly exposed parts of the class.
  public:

    // Here we define our constructor. It takes two argument,
    // which we will use to initialise our member variables in
    // our implementation class.
    SimpleClass(std::string name, int val);

    // This is a destructor, which is ran when the object goes out 
    // of scope or is explicitly destroyed. We don't usually need to
    // define one, as a default one is given. However, for the sake
    // of demonstration we will.
    ~SimpleClass();

    // A method we can call to print the contents of the class
    void print();
};