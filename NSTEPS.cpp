#include<iostream>
using namespace std;

int main()
{
    int t,x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        if((y < x-2) || (y > x) || (y == x-1)){
            cout<<"No Number";
        }
        else{
            if(x%2==0){
                if(y==x)
                    cout<<2*x;
                else
                    cout<<2*x - 2;
            }
            else{
                if(y==x)
                    cout<<2*x -1;
                else
                    cout<<2*x-3;
            }
        }
        cout<<endl;
    }
    return 0;

}


