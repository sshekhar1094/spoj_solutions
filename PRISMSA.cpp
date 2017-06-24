#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;

int main(){
    double v,a,h,s;
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lf", &v);
        a =  pow(4*v, 0.3333333333);
        h = pow(4*v, 0.3333333333) / sqrt(3);
        s = a*a*sqrt(3)/2 + 3*a*h;
        printf("%.10f\n", s);
    }
    return 0;
}
