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

class B : public A{
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

class C : public B{
private:
    int cx;
public:
    C(int a, int b, int c) : B(a, b)
    {
        cx = c;
        cout << "Constructor of class C called." << endl;
    }
    void sumMembers()
    {
        int sum = A::getAx() + B::getBx() + cx;
        cout << "Sum of ax, bx, and cx: " << sum << endl;
    }
    ~C()
    {
        cout << "Destructor of class C called." << endl;
    }
};

int main()
{
    C c(60,70,100);
    c.sumMembers();
    return 0;
}
