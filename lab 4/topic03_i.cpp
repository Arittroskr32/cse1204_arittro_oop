#include<bits/stdc++.h>
using namespace std;
class A{
private:
    int ax;
public:
    A(int a)
    {
        ax = a;
        cout << "A Constructor called"<< "\n";
    }
    int getAx()
    {
        return ax;
    }
    ~A()
    {
        cout << "A destructor called." << endl;
    }
};
class B : public A{
private:
    int bx;
public:
    B(int a, int b) : A(a) // B b(2,4)
    {
        bx = b;
        cout
            << "B Constructor called"<< "\n";
    }
    int sum()
    {
        return A::getAx() + bx;
    }
    ~B()
    {
        cout << "B destructor called." << endl;
    }
};

int main()
{
    B b(50,60);
    int result = b.sum();
    cout << "Sum of ax and bx: " << result << endl;
    return 0;
}
