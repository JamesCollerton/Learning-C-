#include "simple_class.h"

#pragma once

// This entire class cannot access the members of
// SimpleClass, only the function can. 
class FriendFunctionClass {
  
    public:
        void print(SimpleClass* simpleClass);
};