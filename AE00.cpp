#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
    int n,i,j;
    long long ct=0;
    cin>>n;
    for(i=1; i<=sqrt(n); i++){
        for(j=i+1; i*j<=n; j++)
            ct++;
    }
    ct = ct + int(sqrt(n));
    printf("%lld\n", ct);


    return 0;
}
