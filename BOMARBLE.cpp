#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;

int main()
{
    long long a[1001];
    a[0]=0; a[1]=5; //a[2]=12; a[3]=22;
    for(int i=2; i<1001; i++)
        a[i] = a[i-1] + 3*(i-1) + 4;

    int n;
    while(1){
    scanf("%d", &n);
    if(n==0)
        return 0;
    printf("%lld\n", a[n]);
    }
    return 0;
}
