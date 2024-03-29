#include<bits/stdc++.h>
using namespace std;
class A{
private:
    int ax;
public:
    A(int a)
    {
        ax = a;
        cout << "Constructor of class A called." << endl;
    }
    int getAx()
    {
        return ax;
    }
    ~A()
    {
        cout << "Destructor of class A" << endl;
    }
};
class B{
private:
    int bx;
public:
    B(int b)
    {
        bx = b;
        cout << "Constructor of class B called." << endl;
    }
    int getBx()
    {
        return bx;
    }
    ~B()
    {
        cout << "Destructor of class B" << endl;
    }
};

class C : public A, public B
{
private:
    int cx;
public:
    C(int a, int b, int c) : A(a), B(b)
    {
        cx = c;
        cout << "Constructor of class C called." << endl;
    }
    int sumValues()
    {
        return A::getAx() + B::getBx() + cx;
    }
    ~C()
    {
        cout << "Destructor of class C" << endl;
    }
};

int main()
{
    C c(50,100,150);
    cout << "Sum of ax, bx, and cx: " << c.sumValues() << endl;
    return 0;
}
