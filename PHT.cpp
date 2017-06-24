#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
    int t,s=1;
    long long n, ans;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        ans = sqrt(n+1) - 1;
        printf("Case %d: %lld\n", s, ans);
        s++;
    }
    return 0;
}
