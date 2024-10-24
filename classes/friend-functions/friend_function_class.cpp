#include "simple_class.h"
#include "friend_function_class.h"

// Notice this class includes the 'true' header
// of SimpleClass, as we actually need to know
// about the contents.
void FriendFunctionClass::print(SimpleClass& simpleClass) {
    std::cout << "Simple class name " << simpleClass.m_name << std::endl;
};