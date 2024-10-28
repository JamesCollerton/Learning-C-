#include <iostream>

#pragma once

// TODO:
//  - When are copy constructors used?
//  - What are special member functions, and does C++ generate the move constructor?

// Copy constructors can be used with the below syntax:

// CopyAndMoveClass class_to_copy("Initial value");
// CopyAndMoveClass copied_class = class_to_copy; // < Copy constructor called!

// Here we are _constructing_ `copied_class_a` by _copying_ 
// the contents of `class_to_copy_a`. In a lot of languages 
// we do this without thinking, and C++ will generally let 
// us do the same by generating default copy constructors. 
// Only in certain circumstances (covered soon) do we define 
// our own.

// Move constructors can be used with the below syntax:

// CopyAndMoveClass class_to_move("Initial value");
// CopyAndMoveClass moved_class = std::move(class_to_move);

// Here we are _constructing_ `moved_class_a` by _moving_ the contents
// of `class_to_move_a` into it. Move constructors are optional and, 
// unless you specify one, the copy constructor will be called.

// With a move constructor we are usually concerned with transferring
// ownership of some data. For example, let's say we have a pointer to
// an object as part of a class. When we move-construct class A from
// class B, we want class A to have a pointer to the existing data class
// B used to point to (emphasis on the _used_).

// Contrast this to a copy constructor, which would make a full duplicate
// of the underlying data.

// TODO: Maybe a diagram.

// A complimentary concept are copy and move assignment operators. We call
// them as below.

// CopyAndMoveClass class_to_copy("Initial value");
// CopyAndMoveClass copied_class;
// copied_class = class_to_copy; // < Copy assignment called

// CopyAndMoveClass class_to_move("Initial value");
// CopyAndMoveClass moved_class;
// moved_class = std::move(class_to_move);

// They are for cases when we don't necessarily want to construct the object
// straight away. We'll outline why we might need these in the complimentary
// 0/3/5 rule section.

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
    // it when it's empty.
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