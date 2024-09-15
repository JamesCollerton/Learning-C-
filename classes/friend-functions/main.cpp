#include "friend_class.h"
#include "friend_function_class.h"
#include "simple_class.h"

// What is the 'extern' keyword for?
// Why do we have friend classes?
    // A friend class can access private and protected members of other classes in which it is declared as a friend. 

// A friend function is able to access members without the need of inheriting the class.
// The friend function acts as a bridge between two classes by accessing their private data.
// It can be used to increase the versatility of overloaded operators.
// It can be declared either in the public or private or protected part of the class.

// Occassionally we may want to expose access to class protected
// and private member variables without inheritance. In this case
// we introduce a friend class or function. These have special access
// to the other class' contents.

// TODO: Can they alter the contents?

int main() {

    SimpleClass simple_class = SimpleClass("Simple class name");

    FriendClass friend_class;
    friend_class.print(simple_class);

    FriendFunctionClass friend_function_class;
    friend_function_class.print(simple_class);

    return 0;
}

