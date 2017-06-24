#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAX 7000001
using namespace std;

int arr[5000001],occ[MAX];
int main(void){
    int n,i,temp,sz;
    memset(arr,0,sizeof(int)*MAX);
    memset(occ,0,sizeof(int)*MAX);

    occ[0]=1;
    for(i=1;i<=50;i++){
        temp=arr[i-1]-i;
        if(temp<0||(temp>=0&&occ[temp]))
            temp+=2*i;
        arr[i]=temp;
        occ[temp]=1;
        sz = 50;
    }

    while(1){

        scanf("%d",&n);
        if(n<0)break;
        if(n <= sz){
            printf("%d\n", arr[n]);
        }
        else{
            for(i=sz+1;i<=n;i++){
                temp=arr[i-1]-i;
                if(temp<0||(temp>=0&&occ[temp]))
                    temp+=2*i;
                arr[i]=temp;
                occ[temp]=1;
                sz = i;
            }
            printf("%d\n",arr[n]);
        }


    }

    return 0;

}
