#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int t,n1,n2,mn,temp;
    scanf("%d", &t);
    while(t--){
        mn = 999999999;
        scanf("%d", &n1);
        int a1[n1];
        for(int i=0; i<n1; i++)
            scanf("%d", &a1[i]);
        scanf("%d", &n2);
        int a2[n2];
        for(int i=0; i<n2; i++){
            scanf("%d", &a2[i]);
            for(int j=0; j<n1; j++){
                temp = a2[i] - a1[j];
                if(temp < 0)
                    temp = temp * (-1);
                if(mn > temp)
                    mn = temp;
                if(mn ==0 )
                    break;
            }
        }
        printf("%d\n", mn);
    }
    return 0;

}
