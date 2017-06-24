#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
    int t,r,v;
    double rmax, ans, G=9.806;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>r>>v;
        cout<<"Scenario #"<<i+1<<": ";
        if(r > v*v/G)
            cout<<"-1\n";
        else{
            ans = 0.5 * asin(r*G/(v*v));
            printf("%.2f\n", ans * 180/(2 * acos(0.0)));
        }

    }
    return 0;
}
