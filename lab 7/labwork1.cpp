#include<iostream>
#include<conio.h>
using namespace std;
struct member{
    int id;
    float height;
    float weight;
    bool exist;
};
int total=0;
struct member mx[1000];

int searchmember(int y){
    int i,flag=-1;
    for ( i = 1; i <=total; i++)
    {
        if(mx[i].id==y){
            flag=i;
            break;
        }
    }
  return flag;  
}
void addmember(){
    cout<<"You are inside addmember()"<<endl;
    cout<<"enter member id"<<endl;
    int x;
    cin>>x;
    if(searchmember(x)==-1){
    total++;
    mx[total].id=x;
    cout<<"Enter height:"<<endl;
    cin>>mx[total].height;
    cout<<"Enter weight:"<<endl;
    cin>>mx[total].weight;
    mx[total].exist=true;
    cout<<"Added member succesfully..."<<endl;
    }
    else{
        cout<<"Sorry member already exist.."<<endl;
    }
    getch();
}
void updatemember(){
    int p,q;
    cout<<"you are inside updatemember()"<<endl;
    cout<<"enter which id member you want to update"<<endl;
    cin>>p;
    q=searchmember(p);
    if(q!=-1){
            cout<<"Enter new id:"<<endl;
            cin>>mx[q].id;
            cout<<"Enter height:"<<endl;
            cin>>mx[q].height;
            cout<<"Enter weight:"<<endl;
            cin>>mx[q].weight;
            cout<<"Updated the member sucessfully"<<endl;
    }
    else cout<<"id is not available"<<endl;
    getch();
} 
void removemember(){
    int p,q;
    cout<<"you are inside removemember()"<<endl;
    cout<<"enter which id member you want to remove"<<endl;
    cin>>p;
    q=searchmember(p);
    if(q!=-1){
        mx[q].exist=false;
        cout<<"Member removed succesfully.."<<endl;
    }
    else cout<<"Member not found..."<<endl;
    getch();
}
void max_height_weight(){
    cout<<"you are inside max_height_weight()"<<endl;
    float max_height=0,max_weight=0;
    for (int i = 1; i <=total; i++)
    {
        if(mx[i].exist!=-1){
            if(mx[i].height>=max_height){
                max_height=mx[i].height;
            }
            else max_height=max_height;
            if(mx[i].weight>=max_weight){
                max_weight=mx[i].weight;
            }
            else max_weight=max_weight;
        }
    }
    cout<<"Maximum height: "<<max_height<<" & max weight: "<<max_weight<<endl;
    getch();
}
void min_height_weight(){
    cout<<"you are inside min_height_weight()"<<endl;
    float min_height=65000,min_weight=65000;
    for (int i = 1; i <=total; i++)
    {
        if(mx[i].exist!=-1){
            if(mx[i].height<=min_height){
                min_height=mx[i].height;
            }
            else min_height=min_height;
            if(mx[i].weight<=min_weight){
                min_weight=mx[i].weight;
            }
            else min_weight=min_weight;
        }
    }
    cout<<"Minimum height: "<<min_height<<" & min weight: "<<min_weight<<endl;
    getch();
}
void avg_height_weight(){
    cout<<"you are inside avg_height_weight()"<<endl;
    int y=0;
    float t_height=0,t_weight=0,avg_height,avg_weight;
    for (int i = 1; i <=total; i++)
    {
        if(mx[i].exist!=-1){
            y++;
            t_height+=mx[i].height;
            t_weight+=mx[i].weight;
        }
    }
    cout<<"average height: "<<(t_height/y)<<" & average weight: "<<(t_weight/y)<<endl;
    getch();
}
float get_bmi(int n){
    float h,w,bmi,meter;
    h=mx[n].height;
    w=mx[n].weight;
    meter=h/100;
    bmi=w/(meter*meter);
    return bmi;
}
void memberbmianalysis(){
    float BMI;
    for (int i = 1; i <=total ; i++)
    {
        int p=mx[i].id;
        int q=searchmember(p);
        if(q!=-1){
            BMI=get_bmi(q);
            cout<<BMI<<endl;
        }
    }
}
void bmi_classification(){
    int p,q;
    float bmi;
    cout<<"you are inside BMI classification()"<<endl;
    cout<<"Enter the id you want to get BMI"<<endl;
    cin>>p;
    q=searchmember(p);
    if(q!=-1){
    bmi=get_bmi(q); 
    cout<<"BMI is: "<<bmi<<endl;
    if(bmi<16) cout<<"Severe Thinness\n";
    else if(bmi>=16 && bmi <17) cout<<"Moderate Thinness\n"; 
    else if(bmi>=17 && bmi <18.5) cout<<"Mild thinness\n";
    else if(bmi>=18.5 && bmi <25) cout<<"Normal\n";
    else if(bmi>=25 && bmi <30) cout<<"Overweight\n";
    else if(bmi>=30 && bmi <35) cout<<"Obese class I\n";
    else if(bmi>=35 && bmi <40) cout<<"Obese class II\n";
    else  cout<<"Obese class III";
    }
    else{
        cout<<"Id is not available"<<endl;
    }
    getch();
}
void displayall(){
    cout<<"position: Id height weight"<<endl;
    int i,p=0;
    for (int i = 1; i <= total; i++)
    {
        if(mx[i].exist){
        cout<<"position:"<<i<<" "<<mx[i].id<<" "<<mx[i].height<<" "<<mx[i].weight<<endl;
        p++;
        }
    }
    cout<<"Total members: "<<p<<endl;
    getch();  
}
int menu(){
    system("cls");
    int op;
    cout<<"\n********** Main Menu ********\n";
    cout<<"    1. Add Member\n";
    cout<<"    2. Update Member\n";
    cout<<"    3. Remove Member\n";
    cout<<"    4. Max Height & Weight\n";
    cout<<"    5. Min Height and Weight\n";
    cout<<"    6. Average Height and Weight\n";
    cout<<"    7. BMI Classification\n";
    cout<<"    8. display all\n";
    cout<<"    0. Exit\n";
    cout<<"    9. Member bmi analysis\n";
    cout<<"    Enter Your option(0-9): ";
    cin>>op;
    return op;
}
int main(){
    int option;
    for ( ; ; )
    {
        option=menu();
        cout<<"In main() option ="<<option<<endl;
        if(option==0){
            cout<<"End of programme....."<<endl;
            break;
        }
        switch(option){
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
    getch(); 
    return 0;
}