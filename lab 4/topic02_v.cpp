#include<bits/stdc++.h>
using namespace std;
class A{
private:
    int x;
protected:
    int y;
public:
    int z;
};

class B : virtual public A{ };
class C : virtual public A{};

class D : public B, public C
{
public:
    void accessMembers()
    {
        // cout << "Value of x (privet member of class A): " << x << endl;
        cout << "Value of y (protected member of class A): " << y << endl;
        cout << "Value of z (public member of class A): " << z << endl;
    }
};

int main()
{
    D d;
    d.accessMembers();
    return 0;
}
