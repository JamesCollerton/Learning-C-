#include <iostream>

class IncorrectClass {

    public:
        std::string* _string_pointer;

        IncorrectClass(std::string str);

        void print();
};
