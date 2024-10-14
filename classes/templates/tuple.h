#pragma once

template <typename A, typename B> class Tuple {
  
    public:
        Tuple(A &a, B &b): m_a(&a), m_b(&b) {};
        // TODO: What does inline do?
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