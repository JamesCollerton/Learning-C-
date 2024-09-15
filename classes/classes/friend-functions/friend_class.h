#include "simple_class.h"

#pragma once

// Here we declare a friend class which can directly
// access the members of the Simple Class (even the private
// ones)
class FriendClass {
  
    public:
        void print(SimpleClass* simpleClass);
};