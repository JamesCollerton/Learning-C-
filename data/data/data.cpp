#include <iostream>
#include <vector> 
#include <map>
#include <stack>

void myFunction() {
    // code to be executed
}

int main() {

    // Pointers
    int a = 10; 
    int b = 20; 

    std::cout << "Value of a:" << a << std::endl; // Prints 10
    std::cout << "Value of b:" << b << std::endl; // Prints 20

    // The '&' symbol is a way of getting the address
    // of the data (the reference to the data, hence it's 
    // called the reference operator). The '*' symbol in 
    // this context is to say the type is 'pointer to an 
    // integer'.

    int* p_a = &a; // p_a is now the address of 'a'
    int* p_b = &b; // p_b is now the address of 'b'

    std::cout << "Address of a:" << p_a << std::endl; // Prints the address of 'a' (e.g. 0x7ffee09344c8)
    std::cout << "Address of b:" << p_b << std::endl; // Prints the address of 'b' (e.g. 0x7ffee09344c4)

    // The '*' symbol in this context is used to 'dereference'
    // the pointer (i.e. retrieve its value).

    std::cout << "Value of a:" << *p_a << std::endl; // Prints: 10
    std::cout << "Value of b:" << *p_b << std::endl; // Prints: 20

    // Now we get a bit crazy. Technically, we can point to anything,
    // even other pointers.

    int** pp_a = &p_a; // Equivalent to &&a
    int** pp_b = &p_b; // Equivalent to &&
    
    std::cout << "Value of a:" << **pp_a << std::endl; // Prints: 10
    std::cout << "Value of b:" << **pp_b << std::endl; // Prints: 20

    // Finally we do some swapping around. Let's change the value of
    // b

    b = 30;

    // All of the below will still 30
    std::cout << "Value of b:" << b << std::endl; 
    std::cout << "Value of b:" << *p_b << std::endl; 
    std::cout << "Value of b:" << **pp_b << std::endl;

    // Now lets change the pointer to a

    p_a = p_b; // We could also do p_a = &b;

    std::cout << "Value of a:" << a << std::endl; // Prints 10
    std::cout << "Value in p_a:" << *p_a << std::endl; // Prints 30
    std::cout << "Value in pp_a:" << **pp_a << std::endl; // Prints 30

    // Experimenting with references

    // Here we introduce two references. One, r_c references a variable,
    // whereas r_d references a value. Notice how for one we need &, for
    // the other we need &&
    int c = 10;
    int& r_c = c;
    int&& r_d = 20;

    std::cout << "Value of r_c:" << r_c << std::endl; // Prints 10
    std::cout << "Value of r_d:" << r_d << std::endl; // Prints 20

    // Here we're changing one of our references to be an alias for
    // another object.
    int e = 30;
    r_c = e;

    std::cout << "Value of r_c:" << r_c << std::endl; // Prints 30

    // Smart pointers

    // Here we create two different unique pointers, pointing to the
    // same thing.
    int x = 10;
    auto u_p1 = std::make_unique<int>(x);
    auto u_p2 = std::make_unique<int>(x);

    std::cout << "Value of u_p1:" << u_p1 << std::endl; // Prints the address of x
    std::cout << "Value of u_p2:" << u_p2 << std::endl; // Prints the address of x

    x = 20;

    std::cout << "Value of *u_p1:" << *u_p1 << std::endl; // Prints the new value of x: 20

    // This would error as we'd be sharing the reference.
    // auto u_p3 = u_p1;

    // Share
    auto s_p1 = std::make_shared<int>(x);
    auto s_p2 = s_p1;

    // In the background there is a counter keeping track
    // of the number of associated pointers (now 2).

    std::cout << "Value of *s_p2:" << *s_p2 << std::endl; // Prints the value of x: 20

    std::weak_ptr<int> w_p1 = s_p1;

    // The counter we referenced earlier will ignore this
    // reference. In order to access the underlying object
    // we need to 'lock' it into a shared pointer, otherwise
    // something may get rid of it while we're trying to look
    // at its contents

    std::cout << "Value of *w_p1:" << *w_p1.lock() << std::endl; // Prints the value of x: 20

    // As an aside we can demonstrate some of the memory
    // issues we might run into with the unsupervised use
    // of pointers.
    
    // This variable is deleted once it goes out of scope as it
    // is allocated on the stack.
    int q = 100;

    // This exists until we explicitly call 'delete', and is allocated
    // on the heap. It's situations like this where we can get into trouble
    // if we don't remember to clean up after ourselves.
    int* p = new int(100);

    // Enter smart pointers! These detect when the data is no longer 
    // referenced and efficiently remove it.
    std::unique_ptr<int> r(new int(100));

    std::cout << "Value of q:" << q << std::endl; // Prints the value of q: 100
    std::cout << "Value of *p:" << *p << std::endl; // Prints the value of p: 100
    std::cout << "Value of *r:" << *r << std::endl; // Prints the value of r: 100

    // Structs

    struct car {
        std::string name;
        int wheels;
        int horsepower;
    };

    car ford = {
        .name = "Ford",
        .wheels = 4,
        .horsepower = 100
    };

    std::cout << "Value of ford.name:" << ford.name << std::endl; // Prints 'Ford'
    std::cout << "Value of ford.wheels:" << ford.wheels << std::endl; // Prints '4'
    std::cout << "Value of ford.horsepower:" << ford.horsepower << std::endl; // Prints '100'

    car* ford_pointer = &ford;

    std::cout << "Value of ford_pointer->horsepower:" << ford_pointer->horsepower << std::endl; // Prints '100'

    // Unions

    union rectangle { 
        int width;
        int height;
    }; 

    union rectangle rect;
    rect.width = 5;

    std::cout << "Value of r.width:" << rect.width << std::endl; // Prints '5'
    std::cout << "Value of r.height:" << rect.width << std::endl; // Prints '5' as well, as sharing address
    std::cout << "Address of r.width:" << &rect.width << std::endl; // Prints '0x7ffee35073d8'
    std::cout << "Address of r.height:" << &rect.height << std::endl; // Prints '0x7ffee35073d8'

    // Containers

    // Initialise a vector with three values. Don't worry too much
    // about the intricacies of the syntax.
    std::vector<int> int_vec{ 100, 200, 300 };
    
    // begin returns an iterator pointing to the first element, which
    // means we need to check what lies underneath. Size just tells us
    // the size of the vector. We see how we can begin iterating through
    // the values etc.
    std::cout << "Value of *int_vec.begin(): " << *int_vec.begin() << std::endl; // Prints '100'
    std::cout << "Value of *int_vec.size(): " << int_vec.size() << std::endl; // Prints '3'

    // We declare a stack and push a single value onto it.
    std::stack<int> int_stack;
    int_stack.push(1);

    // Here we look at what's at the top of the stack. An interesting C++ oddity is
    // top gives a reference to the top element, and pop removes it. In other languages
    // pop both removes and returns the value.
    std::cout << "Value of int_stack.top(): " << int_stack.top() << std::endl; // Prints '1'

    // Initialising a map, where the keys are strings, and values are ints
    std::map<std::string, int> string_to_int_map;
    string_to_int_map["one"] = 1;

    // Accessing the values
    std::cout << "Value of string_to_int_map[\"one\"]: " << string_to_int_map["one"] << std::endl; // Prints '1'

    myFunction();

    // In this expression a:
    //  - Live on the left hand side of an assignment.
    //  - Points to a location in memory.
    //  - Will survive past the end of the expression.
    // Therefore a is an lvalue. 
    // However, 42:
    //  - Couldn't live on the left hand side of the assignment 
    //  - Exists in memory but doesn't point to a location in memory,
    //  - On its own wouldn't exist once the expression had finished.
    // Therefore 42 is an rvalue
    int a = 42;

    // Here we return an exit status to show the program has
    // executed successfully    
    return 0;
}