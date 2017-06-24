#include<iostream>
using namespace std;

int main()
{
    int a,b,c,d;
    string ap="AP",gp="GP";
    while(1){
        cin>>a>>b>>c;
        if( a==0 && b==0 && c==0)
            break;
        if( a+c == 2*b )
            cout<<ap<<" "<<(c+b-a)<<endl;
        else
            cout<<gp<<" "<<(c * (b/a))<<endl;
    }
    return 0;
}

