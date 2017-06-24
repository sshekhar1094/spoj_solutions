#include<iostream>
#include<stdio.h>
#include<math.h>

long long gcd(long long a, long long b){
    long long t;
    while (b != 0){
       t = b;
       b = a % b;
       a = t;
    }
    return a;
}

using namespace std;
int main()
{
    int t;
    long long a,b,hcf;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld", &a, &b);
        hcf = gcd(a,b);
        printf("%lld %lld\n", b/hcf, a/hcf);
    }

    return 0;
}
