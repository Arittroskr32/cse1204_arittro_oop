#include<bits/stdc++.h>
using namespace std;
class Test {
    public:
    int Sum(int n1) {
        return n1;
    }
 
    int Sum(int n1, int n2) {
        return n1+n2;
    }
 
    double Sum(double n1, double n2) {
        return n1+n2;
    }
 
    double Sum(int n1, double n2) {
        return n1 + n2;
    }
 
    double Sum(double n1, int n2) {
        return n1+n2;
    }
};
 
int main() {
    Test t;
    cout << t.Sum(5) << endl;          
    cout << t.Sum(10,10) << endl;      
    cout << t.Sum(7.5,15) << endl;     
    cout << t.Sum(20,9.7) << endl;     
    cout << t.Sum(20.3,30.4) << endl;  
 
    return 0;
}