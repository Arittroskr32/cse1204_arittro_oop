#include<bits/stdc++.h>
using namespace std;          
int main(){
    tuple<int,string,double>tx;
    tx=make_tuple(100,"Kamal",3.5);
    cout<<get<0>(tx)<<"  "<<get<1>(tx)<<"  "<<get<2>(tx)<<endl;
    get<2>(tx)=3.7;
    cout<<"tx is :"<<get<0>(tx)<<"  "<<get<1>(tx)<<"  "<<get<2>(tx)<<endl;
    tuple<int,string,double>bx;
    bx=make_tuple(200,"Rahim",7.9);
    cout<<"bx is :"<<get<0>(bx)<<"  "<<get<1>(bx)<<"  "<<get<2>(bx)<<endl;
    cout<<"After swap"<<endl;
    swap(bx,tx);
    cout<<"tx is now:"<<get<0>(tx)<<"  "<<get<1>(tx)<<"  "<<get<2>(tx)<<endl;
    cout<<"bx is now:"<<get<0>(bx)<<"  "<<get<1>(bx)<<"  "<<get<2>(bx)<<endl;
    return 0;
}