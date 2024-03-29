#include<bits/stdc++.h>
using namespace std;  
vector<int>v;
vector<int>::iterator ptr;

void insertmenu(){
    cout<<"**** Insert Sub Menu ****"<<endl;
    cout<<"     1. Insert at First  "<<endl;
    cout<<"     2. Insert at Last"<<endl;
    cout<<"     3. Insert Before"<<endl;
    cout<<"     4. Insert After"<<endl;
    cout<<"     5. Exit"<<endl;
    cout<<"Enter your option: ";
}

void deletmenu(){
    cout<<"**** Insert Sub Menu ****"<<endl;
    cout<<"     1. Delet at First  "<<endl;
    cout<<"     2. Delet at Last"<<endl;
    cout<<"     3. Delet Before"<<endl;
    cout<<"     4. Delet After"<<endl;
    cout<<"     5. Exit"<<endl;
    cout<<"Enter your option: ";
}

void insert(){
    int x,op1,y;
    for( ; ; ){
        system("pause");
        system("cls");
        insertmenu();
        cin>>op1;
        if(op1==5) break;
        if(op1==1){
            cout<<"Enter the data you want to insert :";
            cin>>x;
            v.insert(v.begin(),x);
            cout<<"Element insert successfully.."<<endl;
            //system("pause");
        }

        if(op1==2){
            cout<<"Enter the data you want to insert :";
            cin>>x;
            v.insert(v.end(),x);
            cout<<"Element insert at last successfully.."<<endl;
            //system("pause");
        }

        if(op1==3){
            cout<<"Enter the data you want to insert :";
            cin>>x;
            cout<<"Enter the next data of inserting data : ";
            cin>>y;
            for (ptr=v.begin(); ptr<=v.end(); ptr++)
            {
                if(*ptr==y){
                    v.insert(ptr,x);
                    cout<<"Data insert successfully"<<endl;
                    break;
                }
                if(ptr==v.end()) cout<<"Second data not found"<<endl;
            }
            //system("pause");
        }

        if(op1==4){
            cout<<"Enter the data you want to insert :";
            cin>>x;
            cout<<"Enter the previous data of inserting data : ";
            cin>>y;
            for (ptr=v.begin(); ptr<=v.end(); ptr++)
            {
                if(*ptr==y){
                    v.insert(ptr+1,x);
                    cout<<"Data insert successfully"<<endl;
                    break;
                }
                if(ptr==v.end()) cout<<"Second data not found"<<endl;
            }
            //system("pause");
        }
        if(op1>4) cout<<"Invalid option to perform.."<<endl;
    }
}   

void delet(){
    int op1,y;
    for( ; ; ){
        system("pause");
        system("cls");
        deletmenu();
        cin>>op1;
        if(op1==5) break;
        if(op1==1){
            v.erase(v.begin());
            cout<<"Element deleted successfully.."<<endl;
            //system("pause");
        }

        if(op1==2){
            v.erase(v.end()-1);
            cout<<"Last element deleted successfully.."<<endl;
            //system("pause");
        }
        
        if(op1==3){
            cout<<"Enter the data which previous data you want to delet : ";
            cin>>y;
            for (ptr=v.begin(); ptr<=v.end(); ptr++)
            {
                if(*ptr==y){
                    v.erase(ptr-1);
                    cout<<"Data deleted successfully"<<endl;
                    break;
                }
                if(ptr==v.end()) cout<<"Second data not found"<<endl;
            }
            //system("pause");
        }
        if(op1==4){
            cout<<"Enter the data which next data you want to delet : ";
            cin>>y;
            for (ptr=v.begin(); ptr<=v.end(); ptr++)
            {
                if(*ptr==y){
                    v.erase(ptr+1);
                    cout<<"Data deleted successfully"<<endl;
                    break;
                }
                if(ptr==v.end()) cout<<"Second data not found"<<endl;
            }
            //system("pause");
        }
        if(op1>4) cout<<"Invalid option to perform.."<<endl;
        
    }
}

void search(){
    int x,i;
    cout<<"Enter the element you want to search :";
    cin>>x;
    for (ptr=v.begin(),i=0; ptr<=v.end(); ptr++,i++)
    {
        if(*ptr==x){
            cout<<"Element found at index :"<<i<<endl;
            break;
        }
        if(ptr==v.end()) cout<<"Element not found...."<<endl;
    }
    //system("pause");
}

void display(){
    cout<<"Displaying element : ";
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    //system("pause");
}

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
    for ( ; ; )
    {
        system("pause");
        system("cls");
        menu();
        int op;
        cin>>op;
        if(op==5) break;
        else{
            switch (op)
            {
            case 1: insert();
                break;
            case 2: delet();
                break;
            case 3: search();
                break;
            case 4: display();
                break;
            default:
                cout<<"Invalid option..."<<endl;
            }
        }
    }
    
      
    return 0;
}