#include<iostream>
#include<stdio.h>
#include<string>
#include<iosfwd>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
map<long long,long long> v;

long long func(long long n){
    long long mx;
    if(n==0) return 0;
    mx = v[n];
    if(mx == 0){
        mx = max(n, func(n/2) + func(n/3) + func(n/4));
        v[n] = mx;
    }
    return mx;
}

int main(){
    long long n;
    long long mx;
    while( scanf("%lld", &n) != EOF){
        v.clear();
        if(n==0) mx =0;
        else mx = func(n);
        printf("%lld\n", mx);
    }
    return 0;
}
