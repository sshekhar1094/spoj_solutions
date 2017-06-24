#include<iostream>
#include<stdio.h>
#include<string>
#include<iosfwd>
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
    long long n;
    long long a[3];
    while(true){
        //scanf("%lld", &n);
        ri(n);
        if(n==0) break;
        long long vol[n];
        long long mn = 1000000000,ans = 0;
        for(int j=0; j<n; j++){
            for(int i=0; i<3; i++){
                //scanf("%lld", &a[i]);
                ri(a[i]);
                if(a[i] < mn) mn = a[i];
            }
            vol[j] = a[0]*a[1]*a[2];
        }
        for(int i=0; i<n; i++)
            ans = ans + vol[i]/(mn*mn*mn);
        printf("%lld\n", ans);
    }
    return 0;
}

