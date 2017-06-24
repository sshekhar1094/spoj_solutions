#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
    long long a,b,c;
    int t;
    cin>>t;
    while(t--){
        scanf("%lld%lld%lld", &a, &b, &c);
        long long ans = a*a - 2*b;
        printf("%lld\n", ans);
    }
    return 0;
}

