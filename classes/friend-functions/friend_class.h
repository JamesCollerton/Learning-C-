#pragma once

#include "simple_class_fwd.h"

// Here we declare a friend class which can directly
// access the members of the Simple Class (even the private
// ones). It also uses the forward declaration.
class FriendClass {
  
    public:
        void print(SimpleClass& simpleClass);
};