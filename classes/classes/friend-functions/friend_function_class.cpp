#include "simple_class.h"
#include "friend_function_class.h"

void FriendFunctionClass::print(SimpleClass* simpleClass) {
    std::cout << "Simple class name " << simpleClass->m_name << std::endl;
};