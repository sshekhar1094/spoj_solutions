#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t,n,r,t1,t2,flag;

    //vector<int> v1,v2;
    scanf("%d", &t);
    for(int j=1; j<=t; j++){
        int a[1500]={0}, b[1500]={0};
        flag=0;
        scanf("%d%d", &n, &r);
        for(int i=1; i<=r; i++){
            scanf("%d%d", &t1,&t2);
            a[t1]++; b[t2]++;
        }
        for(int i=0; i<r; i++){
            if(a[i]>0 && b[i]>0){
                flag=1;
                break;
            }
        }
        if(flag == 0)
            printf("Scenario #%d: spying\n", j);
        else
            printf("Scenario #%d: spied\n", j);
    }
    return 0;
}
