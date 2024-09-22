#include <iostream>

#pragma once

class BaseClassA {

  protected:
    std::string m_protected;

  public:
    std::string m_public;

    BaseClassA(): m_protected("Protected"), m_private("Private"), m_public("Public"){};

  // This will never be accessible by the derived class.
  private:
    std::string m_private;
};