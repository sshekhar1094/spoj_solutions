#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<math.h>
using namespace std;

int main(){
    int t,tim;
    long long n,k,m,pdt;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld%lld", &n, &k, &m);
        tim=0;
        if(k <= m/n){
            tim++;
            pdt = n*k;
            while(k<= m/pdt){
                tim++;
                pdt = pdt * k;
            }
        }
        printf("%d\n", tim);
    }
    return 0;
}

