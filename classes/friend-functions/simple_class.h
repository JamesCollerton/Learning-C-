#pragma once

#include <iostream>
#include "friend_class.h"
#include "friend_function_class.h"

class SimpleClass {
  
    public:
        SimpleClass(std::string name);

    private:
        std::string m_name;

        // This allows the FriendClass to access the private 
        // variables (m_name)
        friend class FriendClass;

        // This allows only a single method within FriendFunctionClass
        // to access m_name
        friend void FriendFunctionClass::print(SimpleClass& simpleClass);
};