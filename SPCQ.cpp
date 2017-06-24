#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

long long digSum(long long n){
    long long sum=0;
    while(n){
        sum = sum + n%10;
        n = n/10;
    }
    return sum;
}

int main()
{
    int t;
    long long n,s;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        while(true){
            s = digSum(n);
            if(n%s == 0){
                printf("%lld\n", n);
                break;
            }
            else n++;
        }
    }
    return 0;
}
