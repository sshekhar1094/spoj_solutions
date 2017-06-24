#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int t,n;
    double ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = (3.0/4.0) - (1.0/(2*(n+1))) + (1.0/(2*(n+2)));

        printf("%.11f\n", ans);
    }

    return 0;
}
