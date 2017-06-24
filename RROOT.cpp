#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int t;
    float ans,n;
    scanf("%d", &t);
    while(t--){
        scanf("%f", &n);
        ans = 1 - ( sqrt(2/n) / 3);
        printf("%.6f\n", ans);
    }
    return 0;
}
