#include<iostream>
#include<stdio.h>
using namespace std;

long long gcd(long long a, long long b){
    long long t;
    while(b){
        t = b;
        b = a%b;
        a = t;
    }
    return a;
}

int main(){
    long long a,b;
    while(1){
        cin>>a>>b;
        if(a==0)
            break;
        if(a==b)
            cout<<"1\n";
        else{
            if(a>b && a%b==0)
                cout<<a/b<<endl;
            else if(b>a && b%a==0)
                cout<<b/a<<endl;
            else
                cout<< ( a/gcd(a,b) ) * b<<endl;
        }

    }
    return 0;
}


