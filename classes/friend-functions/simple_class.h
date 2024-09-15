#include <iostream>

#pragma once

// This class allows the friend class to
// access its private variables.
class SimpleClass {
  
    public:
        SimpleClass(std::string name);

    private:
        std::string m_name;

    friend class FriendClass;

    // Now this method can access the private
    // variables.
    friend void FriendFunctionClass::print(SimpleClass& simpleClass);
};