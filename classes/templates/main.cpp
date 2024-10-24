#include <iostream>
#include "tuple.h"

// TODO: Difference between templates and generics.
// TODO: What is template metaprogramming?
// TODO: What is template specialization?
// TODO: What does inline do?

// Templates are used to generalise code over data types. For
// example, we may have a 'List' class that can be used on lots
// of different types (a list of integers, a list of string etc.). 
// We don't want to write a different List class each time we introduce 
// a new type, so we would employ templates.

// There are function templates, and class templates. They're best
// demonstrated by example.

// This function uses templates. It takes in any two variables,
// comparing them and returning the minimum. How the comparison works,
// and what 'minimum' means will depend on the type T. The template
// is expanded at compiler time.
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

    // We've deduced the type here. Template argument deduction 
    // automatically deduces the data type of the argument passed 
    // to the class or function templates. This allows us to 
    // instantiate the template without explicitly specifying the data type.
    std::cout << "Min of two ints: " << min(1, 10) << std::endl;

    auto a = 'a';
    auto b = 'b';

    // Now we declare a tuple containing two `char` objects. It could
    // just have easily been two strings.
    auto tuple = Tuple<char, char>(a, b);

    std::cout << "A: " << *tuple.getA() << std::endl;
    std::cout << "B: " << *tuple.getB() << std::endl;
    // std::cout << "Min of Tuple values: " << min(tuple.getA(), tuple.getB()) << std::endl;

    return 0;
}

