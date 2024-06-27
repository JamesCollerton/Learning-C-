#include <iostream>

// TODO: Why use const?

struct car {
    std::string name;
    int wheels;
    int horsepower;
};

void printCarDetails(car &c) {
    std::cout << "----" << std::endl;
    std::cout << "Value of c.name: " << c.name << std::endl;
    std::cout << "Value of c.wheels: " << c.wheels << std::endl;
    std::cout << "Value of c.horsepower: " << c.horsepower << std::endl;
    std::cout << "----" << std::endl;
}

car changeCarByValue(car c) {
    c.name = "Mazda";
    c.horsepower = 200;
    return c;
}

car changeCarByReference(car &c) {
    c.name = "Mazda";
    c.horsepower = 200;
    return c;
}

int main() {

    car ford = {
        .name = "Ford",
        .wheels = 4,
        .horsepower = 100
    };

    printCarDetails(ford);

    car v_c = changeCarByValue(ford);
    printCarDetails(ford);
    printCarDetails(v_c);

    car r_c =changeCarByReference(ford);
    printCarDetails(ford);

    // These two are different, they reference the same data, but the
    // references themselves live in different places
    std::cout << "Value of &ford: " << &ford << std::endl;
    std::cout << "Value of &r_c: " << &r_c << std::endl;

    // Here we return an exit status to show the program has
    // executed successfully    
    return 0;
}