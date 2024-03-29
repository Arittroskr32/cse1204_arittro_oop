#include<bits/stdc++.h>
using namespace std;
class A
{
private:
    int x;
public:
    int getValue()
    {
        return x;
    }
    friend void Add(A &obj, int value);
    friend void IncX(A &obj, int m);
    friend void DecX(A &obj, int n);
};
void Add(A &obj, int value)
{
    obj.x = value;
}
void IncX(A &obj, int m)
{
    obj.x += m;
}
void DecX(A &obj, int n)
{
    obj.x -= n;
}

int main()
{
    A obj;
    Add(obj, 30);
    std::cout << "After Add(): x = " << obj.getValue() << endl;
    IncX(obj, 5);
    std::cout << "After IncX(): x = " << obj.getValue() << endl;
    DecX(obj, 3);
    std::cout << "After DecX(): x = " << obj.getValue() << endl;
    return 0;
}
