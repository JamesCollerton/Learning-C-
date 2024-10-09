#include "copy_and_move_class.h"

// TODO: How does this all work in the new world, with unique/ shared/ weak pointers?
// TODO: All the different ways to construct an object

CopyAndMoveClass::CopyAndMoveClass() {
    std::cout << "Default constructor called" << std::endl;
}

// In this constructor we pass a string, make a copy, then point to
// it from our object.  Note, this is pretty funky behaviour, which 
// we probably wouldn't do in real life.
CopyAndMoveClass::CopyAndMoveClass(std::string value) {

    m_value = new std::string(value);

    std::cout << "Normal constructor, copied value into new object" << std::endl;
}

// In the copy constructor we take a reference to another object, then
// make a copy into this one. The initial object remains the same. We've
// taken a bit of a shortcut by passing a value to our 'normal' constructor.
CopyAndMoveClass::CopyAndMoveClass(CopyAndMoveClass &other) : CopyAndMoveClass(*other.m_value) {
    
    std::cout << "Copy constructor, copied value into new object" << std::endl;
}

// Move constructor. Here we point to the same data in memory, but remove the
// reference from the old object.
CopyAndMoveClass::CopyAndMoveClass(CopyAndMoveClass &&other): m_value(other.m_value) {
    
    other.m_value = nullptr;

    std::cout << "Move constructor, moved value into new object" << std::endl;
}

// Copy assignment. This creates an instance of an object from another, this is
// used to copy an object, then assign the value to another one.
CopyAndMoveClass& CopyAndMoveClass::operator=(const CopyAndMoveClass &other) {
    
    std::cout << "Calling copy assignment" << std::endl;

    // TODO: Which constructor does this call?
    m_value = new std::string(*other.m_value);

    return *this;
}

// Move assignment. This is used to create an instance of an object from another,
// but to remove whatever is in the original
CopyAndMoveClass& CopyAndMoveClass::operator=(CopyAndMoveClass &&other) {

    std::cout << "Calling move assignment" << std::endl;

    if(this != &other){
        m_value = other.m_value;
        other.m_value = nullptr;
    }
    return *this;
}

// Destructor to clean up what is in m_value
CopyAndMoveClass::~CopyAndMoveClass() {
    if(m_value != nullptr) {
        delete m_value;
    }
}

// Helpful print class.
void CopyAndMoveClass::print() {
    if(m_value != nullptr) {
        std::cout << "Value in object: " << *m_value << std::endl;
    } else {
        std::cout << "There is nothing in this object" << std::endl;
    }
    
}