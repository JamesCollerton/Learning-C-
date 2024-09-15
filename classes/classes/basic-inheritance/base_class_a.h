#include <iostream>

#pragma once

// Protected access modifier
// Multiple inheritance

// Here we declare our first base class, which we will
// extend with our derived class.
class BaseClassA {

  // These methods and fields are accessible within the
  // class, but also by any subclasses.
  protected:
    std::string m_baseClassAName;
    int m_baseClassAVal;
    
    std::string getBaseClassAId();

  // This field is only accessible within the class. If
  // I extend BaseClassA I can't directly access it.
  private:
    std::string m_baseClassAId;

  // We then have a public constructor and print method,
  // accessible from anywhere.
  public:

    BaseClassA(std::string name, int val, std::string id);

    void print();
};