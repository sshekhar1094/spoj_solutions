#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int t,n,ct,j;
    cin>>t;
    while(t--){
        ct = 0;
        cin>>n;
        for(j=5; n/j >= 1; j=j*5){
            ct += n/j;
        }
        cout<<ct<<endl;
    }

    return 0;

}

