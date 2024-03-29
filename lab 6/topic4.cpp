#include<bits/stdc++.h>
using namespace std;         
int main(){
    pair<int,string>px;
    px=make_pair(10,"Rajshahi");
    cout<<px.first<<"  "<<px.second<<endl;
    get<0>(px)=20;
    pair<int,string>bx,temp;
    bx=make_pair(50,"Dhaka");
    temp=px;
    px=bx;
    bx=temp;
    cout<<"showing px :"<<px.first<<"  "<<px.second<<endl;
    cout<<"showing bx :"<<bx.first<<"  "<<bx.second<<endl;
    return 0;
}