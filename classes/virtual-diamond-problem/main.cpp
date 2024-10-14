#include <iostream>

class X {
    protected:
        int m_data;
};

class B: public X {};
class C: public X {};
class A: public B, public C {
    public: 
        A() {
            B::m_data = 1;
            C::m_data = 2;
        }
        void printBData() const {
            std::cout << "A: " << B::m_data << std::endl;
        }
        void printCData() const {
            std::cout << "C: " << C::m_data << std::endl;
        }
};

class VirtualB: public virtual X {};
class VirtualC: public virtual X {};
class VirtualA: public VirtualB, public VirtualC {
    public: 
        VirtualA() {
            m_data = 1;
        }
        void printData() const {
            std::cout << "Data: " << m_data << std::endl;
        }
};

int main() {

    const A a; 
    a.printBData();
    a.printCData();

    const VirtualA virtual_a; 
    virtual_a.printData();

    return 0;
}

