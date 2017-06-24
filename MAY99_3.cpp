#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

template <class T>
inline void rd(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-');
		      c=getchar());
	if(c=='-')
		      {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar())
		      i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}

int gcd(int a,int b)
{
    if(b>a)
    return gcd(b,a);
    if(b==0)
    return a;
    return gcd(b,a%b);
}

int main(){
    int t,x,y,z,hcf;
    rd(t);
    while(t--){
        rd(x); rd(y); rd(z);
        if(x<z && y<z)
            printf("NO\n");
        else{
            hcf=gcd(x,y);
            if(z%hcf == 0)
                printf("YES\n");

            else
                printf("NO\n");
        }
    }
    return 0;
}
