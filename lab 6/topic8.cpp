#include<bits/stdc++.h>
using namespace std;
class Queue
{
    queue<int>qt;
    public:
        void push(int x)
        {
            qt.push(x);
            cout<<"Push success"<<endl;
        }
        void pop()
        {
            qt.pop();
            cout<<"Pop success"<<endl;
        }
        void display()
        {
            cout<<"Your queue: ";
            vector<int>temp;
            while(!qt.empty())
            {
                cout<<qt.front()<<" ";
                temp.push_back(qt.front());
                qt.pop();
            }
            cout<<endl;

            for(int v:temp)
            {
                qt.push(v);
            }
        }
        int size()
        {
            return qt.size();
        }
};
void menu()
{
        cout<<"**** Queue Menu ****"<<endl;
        cout<<"   1. Enqueue"<<endl;
        cout<<"   2. Dequeue"<<endl;
        cout<<"   3. Display"<<endl;
        cout<<"   4. Exit"<<endl;
        cout<<"      Enter your option: ";
}
int main()
{
    Queue q;
    while(true)
    {
        system("cls");
        menu();
        int op;
        cin>>op;
        if(op==1)
        {
            cout<<"Enter element to push: ";
            int element;
            cin>>element;
            q.push(element);
        }
        else if(op==2)
        {
           if(q.size()!=0) q.pop();
           else cout<<"Empty queue!! Can't pop"<<endl;
        }
        else if(op==3)
        {
            q.display();
        }
        else if(op==4)
        {
            break;
        }
        cout<<"Press any key to cotinue .....";
        cin.get();
        cin.get();
    }
    return 0;
}