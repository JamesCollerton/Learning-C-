#include "tuple.h"

template <typename A, typename B> 
    Tuple<A, B>::Tuple(const A &a, const B &b): m_a(a), m_b(b) {};

template <typename A, typename B> A* Tuple<A, B>::getA() {
    return m_a;
};

template <typename A, typename B> B* Tuple<A, B>::getB() {
    return m_b;
};