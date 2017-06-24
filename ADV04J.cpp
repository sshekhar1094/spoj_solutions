#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int t,n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int ct =0;
        while(true){
            if(n==3 || n==4){
                ct = ct+3;
                break;
            }
            if(n%2==0){
                n = n/2;
                ct++;
            }
            else{
                n = n/2 + 1;
                ct++;
            }
        }
        printf("%d\n", ct);
    }

    return 0;
}
