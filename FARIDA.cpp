#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long long tab[11000];

template <class T>
inline void ri(T &i){
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

long long func(long long a[], long long n, long long i){
    long long mx;
    if(i>=n){
        tab[i] = 0;
        return 0;
    }
    if(tab[i+1] == -1) tab[i+1] = func(a,n,i+1);
    if(tab[i+2] == -1) tab[i+2] = func(a,n,i+2);
    mx = max( tab[i+1], a[i]+tab[i+2]);
    tab[i] = mx;
    return mx;
}

int main(){
    int t,n;
    long long ans;
    //scanf("%d", &t);
    ri(t);
    for(int z=0; z<t; z++){
        //scanf("%d", &n);
        ri(n);
        //cin>>n;
        long long a[n];
        for(int i=0; i<n; i++){
            //scanf("%lld", &a[i]);
            //cin>>a[i];
            ri(a[i]);
            tab[i] = -1;
        }
        ans = func(a,n,0);
        printf("Case %d: %lld\n", z+1, ans);
        //cout<<"Case "<<z+1<<": "<<ans<<"\n";
        for(int i=0; i<n; i++) tab[i]= -1;
    }
    return 0;
}

