#include <iostream>
#include "tuple.h"

// TODO: Difference between templates and generics.

// Templates are used to generalise code over data types. For
// example, we may have a 'List' class that can be used on lots
// of different classes. We don't want to write a different List
// class each time we introduce a new one, so we would employ
// templates.

// Templates are expanded at compiler time.

// C++ adds two new keywords to support templates: ‘template’ and 
// ‘typename’. The second keyword can always be replaced by the 
// keyword ‘class’.

// We have two different types of template: class and function.

// We can specify default data types.

// Template argument deduction: it can work out which to use
// from the arguments.

// TODO: What is template metaprogramming?
// TODO: What is template specialization?

// This function uses templates. It takes in any two variables,
// comparing them and returning the minimum. How the comparison works,
// and what 'minimum' means will depend on the type T.
template <typename T> T min(T a, T b)
{
    return (a < b) ? a : b;
}

// Here we're using template argument deduction for Tuple:
// Template argument deduction automatically deduces the data
// type of the argument passed to the class or function templates. 
// This allows us to instantiate the template without explicitly 
// specifying the data type.
int main() {

    std::cout << "Min of two ints: " << min<int>(1, 10) << std::endl;

    // TODO: What does this resolve to? Tuple<char, char>?
    Tuple tuple = Tuple('a', 'b');

    std::cout << "Min of two characters: " << min(tuple.getA(), tuple.getB()) << std::endl;

    return 0;
}

