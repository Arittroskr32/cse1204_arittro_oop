#include<iostream>
using namespace std;
class Bank{
    private:
        int id;
        float amount;
        static int n;
    public:
        Bank(){
            id=0;
            amount=0;
            n++;
        }
        Bank(int x,float a){
            id=x;
            amount=a;
            n++;
        }
        void Display(){
            cout<<"Id = "<<id<<endl;
            cout<<"Amount = "<<amount<<endl;
            cout<<"Total client= "<<n<<endl;
        }
        void setdata(int x,float a){
            id=x;
            amount=a;
        }
        void changedata(float x){
            amount=amount+x;
        }
        Bank(Bank &p){
            id=p.id;
            amount=p.amount;
            n++;
        }
        int getn(){
            return n;
        }
        float getamount(){
            return amount;
        }
};
int Bank::n=0;

int main(){
    int sum=0;
    Bank b1(1,400);
    b1.Display();
    Bank b2(b1);
    b2.Display();
    Bank b3;
    b3.setdata(5,100);
    b3.Display();
    b3.changedata(50);
    b3.Display();
    Bank b4;
    b4.setdata(4,400);
    Bank b5;
    b5.setdata(7,700);
    sum=b1.getamount();
    sum=sum+b2.getamount();
    sum=sum+b3.getamount();
    sum=sum+b4.getamount();
    sum=sum+b5.getamount();
    cout<<"Total client: "<<b2.getn()<<endl;
    cout<<"Total amount: "<<sum<<endl;
    cout<<"Thank you very much.."<<endl;

    return 0;
}