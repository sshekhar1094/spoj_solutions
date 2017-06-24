#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;
vector<long long> v;

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

int main(){
    long long t,n,k,tmp,mid,mx,p,hi,lo,ans;
    rd(t);
    while(t--){
        rd(n); rd(k);
        mx=0; ans=0;
        for(int i=0; i<n; i++){
            rd(tmp);
            v.push_back(tmp);
            if(tmp > mx) mx = tmp;
        }
        //mid = (v[0] + v[n-1] + 1)/2;
        hi = mx; lo = 1;
        //cout<<"here";
        while(lo <= hi){
            p = 0;
            mid = lo + (hi - lo)/2;
            for(int i=0; i<n; i++){
                tmp = v[i] / mid;
                p = p + tmp;
            }
            if(p >= k) {
                lo = mid+1;
                ans = mid;
            }
            else hi = mid-1;
        }
        printf("%d\n", ans);
        v.clear();
    }
    return 0;
}

