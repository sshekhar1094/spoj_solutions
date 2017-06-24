#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int main(){
    int t;
    long long n;
    long long f;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;

        f = sqrt(n);
        if(f*f == n)
            cout<<"Case "<<i+1<<": Yes"<<endl;
            //printf("Case %d: Yes\n", i+1);
        else
            cout<<"Case "<<i+1<<": No"<<endl;
            //printf("Case %d: No\n", i+1);
    }
    return 0;

}


