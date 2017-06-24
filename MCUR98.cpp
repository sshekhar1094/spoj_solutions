#include<iostream>
#include<stdio.h>
#include<string>
#include<iosfwd>
using namespace std;

int digsum(int n){
    int s = n;
    while(n){
        s = s + n%10;
        n = n/10;
    }
    return s;
}

int main(){
    static bool a[1000001];
    int i;
    for(i=1; i<1000000; i++){
        a[digsum(i)] = true;
    }
    for(i=1; i<1000000; i++){
        if(!a[i]){
            //fastWrite(i);
            cout<<i<<endl;
        }

    }

    return 0;
}

