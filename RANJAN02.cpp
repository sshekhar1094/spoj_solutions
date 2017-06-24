#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long func(long long n){
    if(n==0) return 0;
    return 3*func(n-1) + 2;
}

int main(){
    long long t,n;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld",&n);
        printf("%lld\n", func(n));
    }
    return 0;
}
