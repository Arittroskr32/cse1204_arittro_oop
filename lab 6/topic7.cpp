#include<bits/stdc++.h>
using namespace std;
stack<int> s; 

class Stack{
    int arr[100];
    int top=-1;
public:
    void push(){
        int x;
        cout<<"Enter the data to insert :";
        cin>>x;
        if(top<99){
            top=top+1;
            arr[top]=x;
            cout<<"data push successfully\n";
        }
        else{
            cout<<"Stack is full\n";
        }
    }
    void pop(){
        if(top>=0){
            cout<<"pop has done. poped data="<<arr[top]<<endl;
            top=top-1;
        }
        else cout<<"stack is empty\n";
    }
    void display(){
        if(top<0) cout<<"stack is empty\n";
        else{
            for (int i = top; i>=0; i--)
            {
                cout<<arr[i]<<endl;
            }          
        }
    }
    void search(){
        int x;
        cout<<"Enter the data to search :";
        cin>>x;
        for (int i = 0; i <top; i++)
        {
            if(arr[i]==x){
                cout<<"Element found at index :"<<i;
                break;
            }
            if(i==top-1){
                cout<<"Element not found..."<<endl;
                break;
            }
        }
        
    }
};

void menu(){
    cout<<"**** Main Menu ****"<<endl;
    cout<<"1. Insert"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Search"<<endl;
    cout<<"4. Display list"<<endl;  
    cout<<"5. Exit"<<endl;
    cout<<"Enter your option: ";
} 
int main(){
    Stack s;
    for ( ; ; )
    {
        system("pause");
        system("clr");
        menu();
        int op;
        cin>>op;
        if(op==5) break;
        else{
            switch (op)
            {
            case 1: s.push();
                break;
            case 2: s.pop();
                break;
            case 3: s.search();
                break;
            case 4: s.display();
                break;
            default:
                cout<<"Invalid option..."<<endl;
            }
        }
    } 
      
    return 0;
}
