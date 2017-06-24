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

/*inline void fastWrite(int Number){

	if(Number==0){	putchar('0'); putchar('\n'); return; }
	int reversedNumber=0,count=0;
	while(Number%10==0){  count++; Number/=10;	}
	while(Number){ reversedNumber=reversedNumber*10+Number%10; Number/=10;}
	while(reversedNumber){	putchar(reversedNumber%10+'0'); reversedNumber/=10;	}
	while(count--) putchar('0');
	putchar('\n');

}*/

int main()
{
	int t,n,p;
	int b1,b2,b3,ans,mx,ct;
	rd(t);
	for(int k=0;k<t; k++){
        b1=1;b2=1;b3=1;ans=0;
        rd(n); rd(p);
        int a[n][p];
        for(int i=0; i<n; i++){
            mx =0; ct=0;
            for(int j=0; j<p; j++){
                rd(a[i][j]);
                if(a[i][j] > 0) {mx = 1; ct++;}
            }
            if(b2 && mx ==0) b2=0;
            if(b3 && ct == p) b3=0;
        }
        for(int i=0; i<n; i++){
            mx = 0;
            for(int j=0; j<p; j++){
                if(a[j][i] > 0) mx = 1;
            }
            if(mx==0){
                b1 = 0; break;
            }
        }
        ans += b1*4 + b2*2 + b3*1;
        printf("Case %d: %d\n", k+1, ans);
	}
	return 0;
}
