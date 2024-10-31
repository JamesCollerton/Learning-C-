#include <iostream>

class CorrectClass {
    
  public:

    std::string* _string_pointer;

    // 'Normal' constructor
    CorrectClass(std::string str);

    // Copy constructor
    CorrectClass(CorrectClass& correct_class);

    // Move constructor
    CorrectClass(CorrectClass&& correct_class);

    // Copy assignment.
    CorrectClass& operator=(const CorrectClass &other);

    // Move assignment
    CorrectClass& operator=(CorrectClass &&other);

    ~CorrectClass();

    void print();

};
