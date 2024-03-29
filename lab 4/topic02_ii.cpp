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
class B : public A{};
class C : public B{
public:
    void accessMembers()
    {
        // cout << "Value of x (privet member): " << x << endl;
        cout << "Value of y (protected member): " << y << endl;
        cout << "Value of z (public member): " << z << endl;
    }
};
int main(){
    C c;
    c.accessMembers();
    return 0;
}
