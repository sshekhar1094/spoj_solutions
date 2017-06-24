#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
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

long long func(int n){
    int a,b;
    long long p1=1,p2=1;
    if(n > 9) {a = n; b = 9;}
    else { a=9; b=n;}
    for(int i=a+1; i<=n+9; i++)
        p1 = p1 * i;
    for(int i=2; i<=b; i++)
        p2 = p2 * i;
    return p1/p2;
}

int main(){
    int t,no,n;
    long long ans;
    rd(t);
    while(t--){
        rd(no); rd(n);
        ans = func(n);
        printf("%d %lld\n", no, ans);
    }

    return 0;
}



