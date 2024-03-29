#include<bits/stdc++.h>
 
using namespace std;
 
class A {
public:
    void Print() {
        cout << "Inside class A" << endl;
    }
};
 
class B : public A {
public:
    void Print() {
        cout << "Inside class B" << endl;
    }
};
 
int main() {
    A a;
    a.Print(); 
    B b;
    b.Print(); 
    A a2;
    A *p1;
    p1 = &a2;
    p1->Print();
    B b2;
    A *p2;
    p2 = &b2;
    p2->Print(); 
 
    return 0;
}