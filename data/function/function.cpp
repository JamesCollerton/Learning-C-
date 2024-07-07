#include <iostream>

// We use the car struct we defined earlier
struct car {
    std::string name;
    int wheels;
    int horsepower;
};

// This is an example of a function using pass by value. A
// copy of the variable c is created, which is used within
// the function. This means that whatever is originally passed
// in will not be changed. How the copy is created depends on
// the type of data passed in.
car changeCarByValue(car c) {
    c.name = "Mazda";
    c.horsepower = 200;
    return c;
}

// This is pass by reference. Here we don't bother copying the
// variable, we instead pass a reference to the original one. This
// means any changes we make to it are reflected in the original.

// This is useful with larger variables, as it avoids the time and
// memory overhead of copying.

// Notice, we are using a reference, but we don't need to use the
// arrow syntax to access the member variables.
car changeCarByReference(car &c) {
    c.name = "Mazda";
    c.horsepower = 200;
    return c;
}

// This is pass by pointer. The difference between this and pass
// by reference is that a pointer can be reassigned, and can 
// potentially be null. If we made c reference something else 
// within the function this wouldn't be reflected outside, as 
// the pointer itself is copied (pass by value).
car* changeCarByPointer(car *c) {
    c->name = "BMW";
    c->horsepower = 300;
    return c;
}

// This is pass by reference, but using a const to prevent it being
// mutated. Const is different to final in Java, and makes sure you
// don't edit the object.
void printCarDetails(const car &c) {
    std::cout << "----" << std::endl;
    std::cout << "Value of c.name: " << c.name << std::endl;
    std::cout << "Value of c.wheels: " << c.wheels << std::endl;
    std::cout << "Value of c.horsepower: " << c.horsepower << std::endl;
    std::cout << "----" << std::endl;
}

int main() {

    // Create our initial variable and print
    // it to the screen.
    car ford = {
        .name = "Ford",
        .wheels = 4,
        .horsepower = 100
    };
    printCarDetails(ford);

    // Here we change the details by value. Notice
    // the original ford variable stays the same.
    car v_c = changeCarByValue(ford);
    printCarDetails(ford);
    printCarDetails(v_c);

    // Now we change the details by reference. The
    // original ford object has been mutated. An interesting
    // piece of syntax is that we pass the variable itself, and
    // not a reference (no & symbol).
    car r_c = changeCarByReference(ford);
    printCarDetails(ford);

    // These two are different, they reference the same data, but the
    // references themselves are separate and live in different places.
    std::cout << "Value of &ford: " << &ford << std::endl;
    std::cout << "Value of &r_c: " << &r_c << std::endl;

    // Here we change the details using a pointer. We now
    // have to pass the address of our variable.
    car* p_c = changeCarByPointer(&ford);
    printCarDetails(ford);

    // These two are identical, they are the exact same pointer as we
    // passed it into 'changeCarByPointer' and returned it as well.
    std::cout << "Value of &ford: " << &ford << std::endl;
    std::cout << "Value of p_c: " << p_c << std::endl;

    // Here we return an exit status to show the program has
    // executed successfully    
    return 0;
}