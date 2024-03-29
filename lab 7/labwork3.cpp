#include<bits/stdc++.h>
#include <conio.h>
#include <time.h>

using namespace std;

class MyCash{
 private:
  string mobile;
  string name;
  int pin;
  float balance;
 public:
     void setData(string m,string n,int p){
      mobile=m;
      name=n;
      pin=p;
     }
     string getMobile(){
      return(mobile);
     }

};
MyCash mc[1000];
int total=-1;

int Menu1(){
 int op;
 cout<<"Press any key to continue..."<<endl;
 getch();
 system("cls");
 cout<<"*** MyCash Login**"<<endl;
 cout<<" 1. Login"<<endl;
 cout<<" 2. Register"<<endl;
 cout<<" 3. Exit"<<endl;
 cout<<"    Enter Your Option:";
 cin>>op;
 return(op);
}
int Search(string m){
 int i,pos=-1;
 for(i=0;i<=total;i++)
    if(mc[i].getMobile()==m)
        pos=i;
 return(pos);
}
int getPin(){
 string pass="";
 char ch;
 ch=getch();
 while(ch!=13){
   pass.push_back(ch);
   cout<<"*";
   ch=getch();
 }
 return(stoi(pass));
}

void Register(){
 string m,n;
 int p,q;
 int x,o;
 srand(time(0));


 cout<<"\nEnter your Mobile No.:";
 cin>>m;
 q=Search(m);
 if(q<0){
 cout<<"Enter your Name:";
 cin>>n;
 cout<<"Enter your Pin:";
 p=getPin();
 //cout<<"Mobile="<<m<<endl;
 //cout<<"Name="<<n<<endl;
 //cout<<"pin="<<p<<endl;
 x=1000+rand()%9000; //0 to 8999
 cout<<"\nYour OTP:"<<x<<endl;
 cout<<"Enter your OTP:";
 cin>>o;
 if(x==o){
    total++;
    mc[total].setData(m,n,p);
    cout<<"Registration Successful"<<endl;
 }
 else
    cout<<"Invalid OTP..."<<endl;
 }
 else
    cout<<"Sorry, Member already exists..."<<endl;

}
void Login(){
 cout<<"Inside Login"<<endl;
}


int main()
{
   int op;



   for(;;){
    op=Menu1();
    cout<<"op="<<op;
    if(op==3)break;
    switch(op){
     case 1: Login();break;
    case 2: Register();break;
    }
   }
    return 0;
}


/*
for ( ;  ;  )
    {
        int op;
    cout<<"********** MyCash Menu ********\n";
    cout<<"1. Update Me\n";
    cout<<"2. Remove Me\n";
    cout<<"3. Send Money\n";
    cout<<"4. Cash-in\n";
    cout<<"5. Cash-out\n";
    cout<<"6. Pay Bill\n";
    cout<<"7. Check Balance\n";
    cout<<"8. History\n";
    cout<<"9. Logout\n";
    cout<<"Enter Your Option (1-9):_\n"; 
    cin>>op;
    switch(op){
            case 1: addmember();break;
            case 2: updatemember();break;
            case 3: removemember();break;
            case 4: max_height_weight();break;
            case 5: min_height_weight();break;
            case 6: avg_height_weight();break;
            case 7: bmi_classification();break;
            case 8: displayall();break;
            case 9: memberbmianalysis();break;
            default: cout<<"Not a valid option...."<<endl; 
        }
    }
    */