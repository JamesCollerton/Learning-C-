#pragma once

#include "simple_class_fwd.h"

// class SimpleClass {};

// This entire class cannot access the members of
// SimpleClass, only the function can. 
class FriendFunctionClass {
  
    public:
        void print(SimpleClass& simpleClass);
};