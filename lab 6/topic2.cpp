#include <bits/stdc++.h>
using namespace std;

template <typename T,typename U> 
class A{
    T x;
    U y;
public:
    void setData(T x, U y)
    {
        this->x = x;
        this->y = y;
    }
    T getSum()
    {
        return x+y;
    }
};
int main()
{
    A<int,int>aa;
    aa.setData(25,30);
    cout<<aa.getSum()<<endl;
    A<double,double>bb;
    bb.setData(2.45,5.69);
    cout<<bb.getSum()<<endl;
    A<double,int>cc;
    cc.setData(5.45,6);
    cout<<cc.getSum()<<endl;
    return 0;
}