#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;

int main()
{
    long long a[4], ans, i=0;
    while(cin>>a[0]){
        scanf("%lld%lld%lld", &a[1], &a[2], &a[3]);
        sort(a, a+4);
        ans = a[2] + a[3];
        i++;
        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;
}
