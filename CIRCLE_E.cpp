#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    int t;
    double r1,r2,r3,r4;
    cin>>t;
    while(t--){
        cin>>r1>>r2>>r3;
        r4 = (r1*r2*r3) / ( r1*r2 + r2*r3 + r1*r3 + 2*sqrt( r1*r2*r3*( r1+r2+r3 ) ));
        printf("%.6f\n", r4);
    }
    return 0;
}
