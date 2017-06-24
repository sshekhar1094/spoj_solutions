#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iosfwd>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
long long md = 1000000009;
//long long arr[50005];

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
    long long t,n,sum,ct,noz,tm,mns,mx,tmp;
    rd(t);
    while(t--){
        rd(n);
        ct=0; sum =0; mx= -999999999; noz=0; mns=0;
        for(int i=0; i<n; i++){
            rd(tmp);
            if(tmp > 0) sum = sum + tmp;
            else if(tmp == 0) noz++;
            if(tmp > mx){ mx=tmp; mns=0;}
            else if(tmp == mx) mns++;
        }
        if(sum > 0){
            ct=1;
            for(int i=0; i<noz; i++) ct = (ct*2)% md;
        }
        else if(mx == 0){
            sum = 0; ct=1;
            for(int i=0; i<noz; i++) ct = (ct*2)% md;
            ct = ct-1;
        }
        else if(mx < 0){
            sum = mx;
            ct = mns;
        }
        printf("%lld %lld\n",sum, ct);
    }

    return 0;
}
