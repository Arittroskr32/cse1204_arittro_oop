#include<iostream>
#include<math.h>
using namespace std;
class triangle{
    private: 
        int a,b,c;
        static int n;
    public:
        triangle(){
            a=0;
            b=0;
            c=0;
            n++;
        }
        triangle(int x,int y,int z){
            a=x;
            b=y;
            c=z;
            n++;
        }
        void displayedge(){
            if(trianglecheck()){
            cout<<"Three edges are: "<<a<<" "<<b<<" "<<c<<endl;
            cout<<"It's a triangle"<<endl;
            cout<<"Area is: "<<getarea()<<endl;
            cout<<"AParameter is: "<<parameter()<<endl;
            cout<<"triangle no: "<<n<<endl;
            }
            else cout<<"It's not a triangle"<<endl;
        }
        void setedge(int x,int y,int z){
            a=x;
            b=y;
            c=z;
        }
        bool trianglecheck(){
            if(a+b>c && a+c>b && b+c>a) return true;
            else{
                n--;
                return false;
            }
        }
        int parameter(){
            return a+b+c;
        }
        float getarea(){
            float s=(a+b+c)/2;
            float b=s*(s-a)*(s-b)*(s-c);
            return sqrt(b);
        }
        float ar[1000];
        void maxarea(){
            
        }
};
int triangle::n=0;
int main(){
    triangle t1(5,6,7);
    t1.displayedge();
    triangle t2;
    t2.setedge(1,5,6);
    t2.displayedge();
    cout<<t1.parameter()<<endl;
    t1.setedge(8,6,4);
    t1.displayedge();
    
    return 0;
}