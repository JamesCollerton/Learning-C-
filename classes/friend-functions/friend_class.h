#pragma once

#include "simple_class_fwd.h"

// class SimpleClass{};

// Here we declare a friend class which can directly
// access the members of the Simple Class (even the private
// ones)
class FriendClass {
  
    public:
        void print(SimpleClass& simpleClass);
};