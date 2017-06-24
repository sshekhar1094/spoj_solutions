#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <set>
using namespace std;
#define pi 3.14159265358979323846264338

template <class T>
inline void rd(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-'); c=getchar());
	if(c=='-') {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar()) i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}

double height(double v, double rad){
    return (v*v*sin(rad)*sin(rad))/20;
}

double range(double v, double rad){
    return (v*v*sin(2*rad))/10;
}

int main(){
    //cout<<1.571 + 0.5 * atan((-4*10)/10);
    int t;
    double x,y,p,rad,k1,k2,v;
    rd(t);
    while(t--){
        //rd(v); rd(k1); rd(k2);
        cin>>v>>k1>>k2;
        if(k1==0) rad = pi/2;
        else if(k2==0) rad = pi/4;
        else{
            rad = 0.5 * atan((-4*k1)/k2);
            if(rad < 0) rad = pi/2 + rad;
        }
        //cout<<rad<<endl;
        x = range(v,rad);
        y = height(v,rad);
        p = k1*x + k2*y;
        printf("%.3f %.3f\n", rad, p);
        //cout<<x<<" "<<y;
    }
    return 0;
}
