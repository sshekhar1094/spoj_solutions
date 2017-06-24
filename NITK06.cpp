#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t;
    long long n;
    scanf("%d", &t);
    while(t--){
        int flag=0;
        scanf("%lld", &n);
        int a[n];
        for(int i=0; i<n; i++)
            scanf("%lld", &a[i]);
        for(int i=0; i<n-1; i++){
            if(a[i] > a[i+1]){
                flag=1; break;
            }
            else{
                a[i+1] -= a[i];
                a[i] = 0;
            }
        }
        if(a[n-1] != 0) flag=1;
        if(flag==1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

