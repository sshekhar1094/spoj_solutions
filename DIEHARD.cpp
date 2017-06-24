#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
int dp[1100][1100];

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

/*int func(int h, int a, int crr, int k){

    //if(h <= 0 || a <= 0) return k+1;
    if(crr == 1){
        h = h+3;
        a = a+2;
        k++;
        //cout<<k<<" : crr="<<crr<<", h="<<h<<", a="<<a<<endl;
        return max(func(h,a,2,k), func(h,a,3,k));
    }
    else if(crr == 2){
        h = h-5;
        a = a-10;
        k++;
        //cout<<k<<" : crr="<<crr<<", h="<<h<<", a="<<a<<endl;
        if(h <= 0 || a <= 0) return k-1;
        return max(func(h,a,1,k), func(h,a,3,k));
    }
    else if(crr == 3){
        h = h-20;
        a = a+5;
        k++;
        //cout<<k<<" : crr="<<crr<<", h="<<h<<", a="<<a<<endl;
        if(h <= 0 || a <= 0) return k-1;
        return max(func(h,a,1,k), func(h,a,2,k));
    }
}*/

/*int func2(int h, int a, int crr, int k){
    if(h<=0 || k<=0) return k;
    if(crr == 1){
        h = h+3;
        a = a+2;
        k++;
        if(dp[h-5][a-10] == -1) dp[h-5][a-10] = func2(h-5,a-10,2,k);
        if(dp[h-20][a+5] == -1) dp[h-20][a+5] = func2(h-20,a+5,3,k);
        dp[h][a] = 1 + max(dp[h-5][a-10], dp[h-20][a+5]);
    }
    else if(crr == 2){
        h = h-5;
        a = a-10;
        k++;
        if(h<=0 || a<=0) return k-1;
        if(dp[h+3][a+2] == -1) dp[h+3][a+2] = func2(h+3,a+2,1,k);
        //if(dp[h-20][a+5] == -1) dp[h-20][a+5] = func2(h+20,a+5,3,k);
        //dp[h][a] = 1 + max(dp[h+3][a+2], dp[h-20][a+5] );
        dp[h][a] = 1 + dp[h+3][a+2];
    }
    else if(crr == 3){
        h = h-20;
        a = a+5;
        k++;
        if(h<=0 || a<=0) return k-1;
        if(dp[h+3][a+2] == -1) dp[h+3][a+2] = func2(h+3,a+2,1,k);
        //if(dp[h-5][a-10] == -1) dp[h-5][a-10] = func2(h-5,a-10,2,k);
        //dp[h][a] = 1 + max(dp[h+3][a+2], dp[h-5][a-10] );
        dp[h][a] = 1 + dp[h+3][a+2];
    }
    return k;
}*/

int func3( int h , int a , int k , bool f )
    {
      if (h<=0 || a<=0 ) return k ;
      if (dp[h][a] ) return dp[h][a] ;
      if (f) dp[h][a] = max(dp[h][a] , func3 (h+3 , a+2 , k+1 , !f)) ;
      else
         dp[h][a] = max(dp[h][a] ,  max(func3(h-5, a-10, k+1 , !f) , func3(h-20, a+5 ,k+1 ,!f))) ;

     return dp[h][a];
   }

int main(){
    int t,h,a,i;
    rd(t);
    while(t--){
        rd(h); rd(a);
        memset ( dp , 0 , sizeof dp ) ;
        //if(dp[h][a] == -1) dp[h][a] = func2(h,a,1,0);
        //int ans = dp[h][a] ;
        int ans = func3(h,a,-1,1);
        printf("%d\n", ans);
    }
	return 0;
}
