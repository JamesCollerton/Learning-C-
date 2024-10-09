#include "simple_class.h"
#include "friend_class.h"

void FriendClass::print(SimpleClass& simpleClass) {
    std::cout << "Simple class name " << simpleClass.m_name << std::endl;
};