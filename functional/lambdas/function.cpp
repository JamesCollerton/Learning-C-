#include <iostream>

// Assign a Lambda to a variable 'sumTwoIntegers'. The Lambda take two
// integers, a and b, returning their sum.
auto sumTwoIntegers = [](int a, int b) {
  return a + b;
};

void captureExamples() {

  // Here we assign two variables, x and y. We will
  // capture them by value (in which case a copy is made
  // when the Lambda is declared), and then by reference
  // (meaning any changes to their values will be reflected
  // in the function).
  auto x = 10;
  auto y = 1;

  // As we capture the value of x by value, it will always be
  // ten, even if we change it later.
  auto addTen = [x](int a) {
    return x + a;
  };

  // By capturing by reference (using &), we can adjust the value
  // of x and have it reflected in the function.
  auto addX = [&x](int a) {
    return x + a;
  };

  // This syntax, the solitary '=', means that any variables from
  // the surrounding scope, referenced in the function are captured
  // by value.
  auto addOne = [=](int a) {
    return y + a;
  };

  // Equivalent to the above, but capture by reference.
  auto addY = [&](int a) {
    return y + a;
  };

  // 'Capture everything by value, except y, which is by reference'
  auto addTenAndY = [=, &y](int a) {
    return x + y + a;
  };

  // 'Capture everything by reference, except x, which is by value'
  auto addXAndOne = [&, y](int a) {
    return x + y + a;
  };

  x = 20;
  y = 2;

  std::cout << "Add 10 to 5: " << addTen(5) << std::endl;
  std::cout << "Add x to 5: " << addX(5) << std::endl;

  std::cout << "Add 1 to 5: " << addOne(5) << std::endl;
  std::cout << "Add y to 5: " << addY(5) << std::endl;

  std::cout << "Add 10 + y to 5: " << addTenAndY(5) << std::endl;
  std::cout << "Add x + 1 to 5: " << addXAndOne(5) << std::endl;

}

class SimpleClass {
  public:
    int value;

    SimpleClass(int v): value(v) {};

    SimpleClass(SimpleClass &other): value(other.value) {
      std::cout << "Copy constructor" << std::endl;
    };

    SimpleClass(SimpleClass &&other) = default;

    SimpleClass& operator=(const SimpleClass &other) {
      std::cout << "Copy assignment" << std::endl;
      value = other.value;
      return *this;
    }

    SimpleClass& operator=(SimpleClass &&other) = default;
};

void mutableExamples() {

  auto increasingIncrement = [x = 1](int a) mutable {
    return x++ + a;
  };

  std::cout << "Increment 1: " << increasingIncrement(1) << std::endl;
  std::cout << "Increment 2: " << increasingIncrement(1) << std::endl;
  std::cout << "Increment 3: " << increasingIncrement(1) << std::endl;

  SimpleClass simple_class = SimpleClass(1);

  auto incrementValue = [simple_class](int a) mutable {
    simple_class.value++;
    simple_class = SimpleClass(simple_class.value);
    return simple_class.value + a;
  };

  std::cout << "Increment 1: " << incrementValue(1) << std::endl;
  std::cout << "Increment 2: " << incrementValue(1) << std::endl;
  std::cout << "Increment 3: " << incrementValue(1) << std::endl;

  std::cout << "Simple class value: " << simple_class.value << std::endl;

}

void throwExamples() {

  try {
    int age = 15;
    if (age >= 18) {
      std::cout << "Access granted - you are old enough.";
    } else {
      // throw 505;
      throw "This is an error!";
    }
  }
  // This catches everything
  catch (...) {
    std::cout << "Access denied - You must be at least 18 years old.\n";
  }

}

struct SimpleStruct {
  std::string a;
  std::string b;
};

// This is a base class the other two will extend
class BaseClass {
  public:
    BaseClass(std::string value): _value(value) {}
  private:
    std::string _value;
};

// First extension of the base class
class ConcreteClassA: public BaseClass {
  public:
    ConcreteClassA(std::string value, std::string a): BaseClass(value), _a(a) {}
  private:
    std::string _a;
};

// Second extension of the base class
class ConcreteClassB: public BaseClass {
  public:
    ConcreteClassB(std::string value, std::string b): BaseClass(value), _b(b) {}
  private:
    std::string _b;
};

void returnTypeExamples() {

  // Templated Lambdas decltype(a + b)
  auto sum = []<typename A, typename B>(A a, B b) {
    return a + b;
  };

  std::cout << "Sum 1, 2: " << sum(1, 2) << std::endl;

  // Ambiguous return types
  auto create_simple_struct = [](std::string a, std::string b) -> SimpleStruct {
    return { a, b };
  };

  auto simple_struct = create_simple_struct("A", "B");

  std::cout << "Simple struct: " << simple_struct.a << " " << simple_struct.b << std::endl;

  // In this function we need to explicitly tell the compiler
  // we want to return something recognised as the 'BaseClass'
  // otherwise the deduction gets confused between the A and B
  // classes.
  auto create_base_class = [](std::string value, std::string other, bool isAClass) -> BaseClass {
    if(isAClass) {
      return ConcreteClassA(value, other);
    }
    return ConcreteClassB(value, other);
  };

  create_base_class("Value", "A", true);
  create_base_class("Value", "B", false);

}

// Here we declare a function that takes in another
// function (f, which takes two integers and returns
// another) then applies it.
// int apply(int a, int b, int (*f)(int, int)) {
//   return f(a, b);
// }

// We replace the function pointer with std::function
int apply(int a, int b, std::function<int(int, int)> f) {
  return f(a, b);
}

// Here we define a Lambda function as the final argument
// to apply, and carry it out.
void higherOrderFunctionsExamples() {
  auto output = apply(1, 2, [](int a, int b) { return a + b; });
  std::cout << "Output of function: " << output << std::endl;


  // We declare an initial array with values, then a secondary array
  // to store the result into. 
  int arr[] = {1, 2, 3, 4};
  int arr_2[4];

  // Now we call the transform function, which goes along the initial array,
  // carries out the function (doubling) and stores it in the second array.
  std::transform(std::begin(arr), std::end(arr), arr_2, [](int a) { return 2 * a; });
  
  for (int a : arr_2) {
    std::cout << a << std::endl;
  }

}

int main() {

    auto sum = sumTwoIntegers(1, 2);
    
    // captureExamples();
    // mutableExamples();
    // throwExamples();
    // returnTypeExamples();
    higherOrderFunctionsExamples();

    return 0;
}