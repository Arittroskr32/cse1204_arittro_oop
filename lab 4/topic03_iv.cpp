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
    ~B()
    {
        cout << "Destructor of class B called." << endl;
    }
};

class C : public A{
private:
    int cx;
public:
    C(int a, int c) : A(a)
    {
        cx = c;
        cout << "Constructor of class C called." << endl;
    }
    void sumMembers()
    {
        int sum = A::getAx() + cx;
        cout << "Sum of ax and cx: " << sum << endl;
    }
    ~C()
    {
        cout << "Destructor of class C called." << endl;
    }
};

int main()
{
    B b(50,60);
    C c(100,120);
    c.sumMembers();
    return 0;
}
