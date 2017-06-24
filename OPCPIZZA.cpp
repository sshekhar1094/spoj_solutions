#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iosfwd>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
int a[100000];

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

inline void fastWrite(int Number){

	if(Number==0){	putchar('0'); putchar('\n'); return; }
	int reversedNumber=0,count=0;
	while(Number%10==0){  count++; Number/=10;	}
	while(Number){ reversedNumber=reversedNumber*10+Number%10; Number/=10;}
	while(reversedNumber){	putchar(reversedNumber%10+'0'); reversedNumber/=10;	}
	while(count--) putchar('0');
	putchar('\n');

}
int bin(int a[],int i,int m,int l,int u)
{
     int mid;
     if(l<=u)
    {
          mid=(l+u)/2;
          if(m==a[mid] && mid!=i)
              return 1;
          else if(m<a[mid])
              return bin(a,i,m,l,mid-1);
          else
              return bin(a,i,m,mid+1,u);
     }
       return 0;
}
int main()
{
	int t,m,n,i,ans;
    scanf("%d",&t);;
    while(t--)
    {
    ans=0;
    rd(n); rd(m);
    for(i=0;i<n;i++)
        rd(a[i]);
    sort(a,a+n);
    for(i=0;i<n;i++)
        ans=ans+bin(a,i,m-a[i],i,n-1);
    //printf("%d\n",ans);
    fastWrite(ans);
    }
	return 0;
}
