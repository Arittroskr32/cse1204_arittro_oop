#include<bits/stdc++.h>
#include<array>
using namespace std;

void display(array<int,6>arr){
    for(auto p:arr){
        cout<<p<<" ";
    }
    cout<<endl;
}        
int main(){
    array<int,6>arr={10,60,30,70,20};
    cout<<arr.at(2)<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.back()<<endl;
    arr.fill(5);
    display(arr);
    if(arr.empty()) cout<<"Empty"<<endl;
    else cout<<"Not empty"<<endl;
    cout<<arr.size()<<endl;
    cout<<arr.max_size()<<endl;
    cout<<arr.begin()<<endl;
    cout<<arr.end()<<endl;
    return 0;
}