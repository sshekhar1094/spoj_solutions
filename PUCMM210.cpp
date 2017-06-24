#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;

long long a, arr[1000000];
long long MX = 1000000003;

int main(){
    arr[0]=0;
    long long sum =0;
    for(int i=1; i<1000001; i++){
        long long x;
        if(i%2 == 0)
            x = ( ((i/2)%MX) * (i+1)%MX);
        else
            x = ( ((i)%MX) * ((i+1)/2)%MX);
        a =  (x%MX * x%MX) % MX;
        arr[i] = (arr[i-1] + a)%MX;
    }
    int t;
    long long n;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        printf("%lld\n", arr[n]);
    }
    return 0;
}

