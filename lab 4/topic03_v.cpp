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
        cout << "Destructor of class A called." << endl;
    }
};

class B : virtual public A{
private:
    int bx;
public:
    B(int a, int b) : A(a)
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
        cout << "Destructor of class B called." << endl;
    }
};

class C : virtual public A{
private:
    int cx;
public:
    C(int a, int b) : A(a)
    {
        cx = b;
        cout << "Constructor of class C called." << endl;
    }
    int getCx()
    {
        return cx;
    }
    ~C()
    {
        cout << "Destructor of class C called." << endl;
    }
};

class D : public B, public C{
private:
    int dx;
public:
    D(int a, int b, int c, int d) : A(a), B(a, b), C(a, c)
    {
        dx = d;
        cout << "Constructor of class D called." << endl;
    }
    void sumMembers()
    {
        int sum = A::getAx() + B::getBx() + C::getCx() + dx;
        cout << "Sum of ax, bx, cx, and dx: " << sum << endl;
    }
    ~D()
    {
        cout << "Destructor of class D called." << endl;
    }
};

int main()
{
    D d(10,11,12,13);
    d.sumMembers();
    return 0;
}
