#pragma once

// Here we're declaring our tuple has two different
// generic types. They could be strings, integers
// etc. and don't have to be the same.
template <typename A, typename B> class Tuple {
  
    public:
        Tuple(A &a, B &b): m_a(&a), m_b(&b) {};
        
        inline A* getA() {
            return m_a;
        };
        inline B* getB() {
            return m_b;
        };

    private:
        A* m_a;
        B* m_b;
};