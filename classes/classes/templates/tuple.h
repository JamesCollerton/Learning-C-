#pragma once

template <typename A, typename B> class Tuple {
  
    public:
        Tuple(const A &a, const B &b);
        A* getA();
        B* getB();

    private:
        A* m_a;
        B* m_b;
};