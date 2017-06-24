#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
#define pi 3.141592653589
using namespace std;


int main()
{
    double r1,r2,h1,h2,v1,v2,w,h,t;
    while( true){
        cin>>w>>h ;
        if(w==0 && h==0)
            break;
        if(w>h){
            t = w;
            w = h;
            h = t;
        }
        r1 = w/(2.0*pi);
        h1 = h- 2.0*r1;
        r2 = min( h/(2.0*(pi+1)) , w/2.0 );
        h2 = w;
        v1 = pi * r1 * r1 * h1;
        v2 = pi * r2 * r2 * h2;
        if(v1>v2)
            printf("%.3f\n", v1);
        else
            printf("%.3f\n", v2);
    }
    return 0;
}

