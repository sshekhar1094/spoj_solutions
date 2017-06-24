#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
char str1[2014];
char str2[2014];
int dp[2014][2014];

/*template <class T>
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
}*/

/*inline void fastWrite(int Number){

	if(Number==0){	putchar('0'); putchar('\n'); return; }
	int reversedNumber=0,count=0;
	while(Number%10==0){  count++; Number/=10;	}
	while(Number){ reversedNumber=reversedNumber*10+Number%10; Number/=10;}
	while(reversedNumber){	putchar(reversedNumber%10+'0'); reversedNumber/=10;	}
	while(count--) putchar('0');
	putchar('\n');

}*/


int main(){

	int t;
	scanf("%d",&t);
	while(t--){
    scanf("%s%s",str1,str2);
	int d1,d2,d3,i,j,l1,l2;
	 l1=strlen(str1);
	 l2=strlen(str2);
	for( i=0;i<=l1;i++)
	   dp[i][0]=i;
    for( j=1;j<=l2;j++)
       dp[0][j]=j;
     for( i=1;i<=l1;i++){
     	for( j=1;j<=l2;j++){
     		d1=((str1[i-1]==str2[j-1])?0:1)+dp[i-1][j-1];
            d2=dp[i][j-1]+1;
		    d3=dp[i-1][j]+1;
			if(d1<d2&&d1<d3)
               dp[i][j]=d1;
            else{
            	if(d2<d3)
            	   dp[i][j]=d2;
         	     else
         	     dp[i][j]=d3;
            }
     	}
     }
    printf("%d\n", dp[l1][l2]);
	}
}


