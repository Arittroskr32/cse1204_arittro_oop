#include<bits/stdc++.h>
using namespace std;


int main()
{
    int i;
    int ax[5]={10,20,30,40,50};
    cout<<"Enter Index:";
    cin>>i;
    try
    {
        if(i>=0 && i<5){
            throw(i);
            cout<<"now a am"<<endl;
        }
        else if(i>=5) throw("Out of Range Error");
        else throw((float)i);
    }
    catch(int x)
    {
        cout<<"value is "<<ax[x]<<endl;
    }
    catch(const char *s)
    {
        cout<<s<<endl;
    }
    catch(...)
    {
        cout<<"Input is not valid"<<endl;
    }

    return 0;
}