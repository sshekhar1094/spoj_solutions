#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

#define mx 10000000
bool prms[mx];
long long lst[mx];

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

void sieve(){
    long long int i,num,j;
    for(i=2;i<mx;i++){
        if(prms[i]==0){
            j=2;
            lst[i]=i;
            while((num = j*i) < mx){
                if(prms[num]==0)
                    lst[num]=i;
                prms[num]=1;
                j++;
            }
        }
    }
}

long long int func(int n){
    long long int i;
    long long int ans=0;
    for(i=2;i<=n;i++)
        ans += lst[i];
    return ans;
}

int main(){
    long long int t,i,n,ans;
    sieve();
    scanf("%lld",&t);
    for(i=0;i<t;i++){
        scanf("%lld",&n);
        ans = func(n);
        printf("%lld\n",ans);
    }
    return 0;
}
