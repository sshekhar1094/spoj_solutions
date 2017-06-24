#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

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

int main(){
    long long m,sum=0,ct=0;
    int n;
    scanf("%d%lld", &n, &m);
    long long v[n];
    long long mx=0, mn=1000000000;
    for(int i=0; i<n; i++){
        ri(v[i]);
        if(v[i] > mx) mx=v[i];
        if(v[i] < mn) mn = v[i];
    }
    //cout<<mn<<endl;
    long long l=mn, h=mx, mid,ans;
    while(l<h){
		mid=l+(h-l)/2;
		sum=0;
		for(int i=0;i<n;i++){
			if(mid<v[i]){
				sum+=(v[i]-mid);
			}
		}
		if(sum<m)		h=mid;
		else{
			ans=mid;
			l=mid+1;
		}
	}
    printf("%lld\n", ans);

    return 0;
}


