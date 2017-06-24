#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    float r,s;
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>r;
        s = (16*r*r +1)/4;
        printf("Case %d: %.2f\n", i, s);
    }

    return 0;
}
