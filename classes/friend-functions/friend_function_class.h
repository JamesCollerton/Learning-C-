#pragma once

#include "simple_class_fwd.h"

// This entire class cannot access the members of
// SimpleClass, only the function can. Notice it
// uses the forward declaration of SimpleClass to
// avoid the cyclic dependency.
class FriendFunctionClass {
  
    public:
        void print(SimpleClass& simpleClass);
};