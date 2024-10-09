#include <iostream>

#pragma once

// Copy constructors:
//  Copy one object into another
// Move constructors:
//  Move the object into this one, the old object is no longer valid
//  Move constructors are optional, if you don’t provide it then the 
//  copy constructor will be called.
//  A concept of moving ownership, the data stays in the same place on 
//  the heap, however the old object can no longer reference it, the new 
//  object owns this reference.

// The only difference between a copy constructor and a move constructor 
// is whether the source object that is passed to the constructor will 
// have its member fields copied or moved into the new object.

// Imagine an object containing a member pointer to some data that is 
// elsewhere in memory.

// A copy constructor must leave the source object intact, so it must 
// allocate its own copy of the object's data for itself. Both objects 
// now refer to different copies of the same data in different areas of 
// memory 

// A move constructor, on the other hand, can simply "move" the data by 
// taking ownership of the pointer that refers to the data, leaving the 
// data itself where it resides. The new object now points at the original 
// data, and the source object is modified to no longer point at the data. 
// The data itself is left untouched.

class CopyAndMoveClass {
  
  private:
    // This is the value stored in our class. We will be copying and 
    // moving this.
    std::string* m_value;

  public:

    // Here we declare a zero-argument constructor. We will
    // see it is called by copy and move assignment.
    CopyAndMoveClass();

    // This is our 'normal' constructor, which takes a value
    // we want to initialise the object with.
    CopyAndMoveClass(std::string value);

    // Copy constructor, this takes a reference to another object,
    // which we will copy from.
    CopyAndMoveClass(CopyAndMoveClass &other);

    // Move constructor, this takes an rvalue reference - something
    // that we expect to live temporarily. This makes sense as we will
    // be moving the data from it, so we don't expect to continually use
    // it.
    CopyAndMoveClass(CopyAndMoveClass &&other);

    // Copy assignment.
    CopyAndMoveClass& operator=(const CopyAndMoveClass &other);

    // Move assignment
    CopyAndMoveClass& operator=(CopyAndMoveClass &&other);

    // Destructor
    ~CopyAndMoveClass();

    // Helpful function for printing what we have in an object
    void print();
};