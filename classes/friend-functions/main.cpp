#include "friend_class.h"
#include "friend_function_class.h"
#include "simple_class.h"

// TODO: What is the 'extern' keyword for?
// TODO: Can friend classes access protected data?
    // Yes
// TODO: Can friend functions alter contents?
    // Yes

// We have two types of 'friend' data: friend classes and friend functions. Friend
// classes are allowed to access and alter the protected and private data of another class
// without inheriting from it. A friend function is a function with the same capabilities.

int main() {

    // Create an instance of SimpleClass
    SimpleClass simple_class = SimpleClass("Simple class name");

    // This can print the private m_value field as it is a
    // friend class.
    FriendClass friend_class;
    friend_class.print(simple_class);

    // This can print the private m_value field as the 'print'
    // method has access to it.
    FriendFunctionClass friend_function_class;
    friend_function_class.print(simple_class);

    return 0;
}

