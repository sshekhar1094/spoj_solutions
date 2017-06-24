#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    double n,ans;
    scanf("%d",&t);
    while(t--){
        cin>>n;
        ans = n/(n+1);
        printf("%.8f\n", ans);
    }
    return 0;
}
