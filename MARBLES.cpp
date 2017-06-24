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

template <class T>
inline void rd(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-'); c=getchar());
	if(c=='-') {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar()) i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}

long long fact(int n, int m){
    if(m>n-m) m=n-m;
    long long ans=1;
    for(int i=0;i<m;i++) ans=ans*(n-i)/(i+1);
    return ans;
}

int main(){
    int t,n,k;
    long long ans;
    rd(t);
    while(t--){
        rd(n); rd(k);
        if(n == k){
            printf("1\n");
            continue;
        }
        ans = fact(n-1, k-1);
        printf("%lld\n", ans);
    }
    return 0;
}
