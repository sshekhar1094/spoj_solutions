#include<iostream>
#include<stdio.h>
using namespace std;

int gcd(long long  a, long long b){
    long long t;
    while(b){
       t = b;
       b = a % b;
       a = t;
    }
    return a;
}

int main(){
    int t;
    long long n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)
            cout<<"0\n";
        else{
        for(long long j=n/2; j>=1; j--){
            if(gcd(j,n) == 1){
                cout<<j<<endl;
                break;
            }
        }
        }
    }
    return 0;
}
