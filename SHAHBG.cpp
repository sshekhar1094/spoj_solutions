#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,temp,ct=0,mx=0,i;
    vector<int> v(30000);
    scanf("%d", &n);
    while(n--){
        scanf("%d", &temp);
        if(v[temp-1]==0 && v[temp+1]==0) ct++;
        else if(v[temp-1]==1 && v[temp+1]==1) ct--;
        v[temp] = 1;
        printf("%d\n", ct);
    }
    printf("Justice\n");
    v.clear();
    return 0;
}
