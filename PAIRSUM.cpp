#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <map>
using namespace std;
long long S[100000], Sq[100000], arr[100000];

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

void fll(long long n){
    S[0] = arr[0]; Sq[0]=arr[0]*arr[0];
    for(long long i=1; i<n; i++){
        S[i] = arr[i] + S[i-1];
        Sq[i] = Sq[i-1] + arr[i]*arr[i];
    }
}

int main(){
    long long n,m,u,v,ans,suv,squv;
    rd(n);
    for(long long i=0; i<n; i++) rd(arr[i]);
    rd(m);
    fll(n);
    while(m--){
        rd(u), rd(v);
        if(u==0) { suv = S[v]; squv = Sq[v];}
        else { suv = S[v] - S[u-1]; squv = Sq[v] - Sq[u-1];}
        ans = (suv*suv + squv)/2;
        printf("%lld\n", ans);
    }
	return 0;
}
