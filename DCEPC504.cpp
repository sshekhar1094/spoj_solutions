#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;

long long func(long long n){
    if(n==0) return 0;
    if(n%2 == 0) return func(n/2);
    else return 1-func(n/2);
}

int main()
{
    long long n,k,t;
    long long d;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld", &n, &k);
        d = func(k-1);
        if(d==0)
            printf("Male\n");
        else
            printf("Female\n");
    }
    return 0;
}

