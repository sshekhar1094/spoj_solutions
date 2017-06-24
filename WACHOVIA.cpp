#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iosfwd>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
int K[60][1050], val[60], wt[60];

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

/*int KS(long long c, long long i){
    if(i>n){
        tab[c][i] = 0;
        return 0;
    }
    if(W[i] > c){
        if(tab[c][i+1] == 0) tab[c][i+1] = KS(c,i+1);
        return tab[c][i+1];
    }
    else{
        if(tab[c][i+1] ==0) tab[c][i+1] = KS(c,i+1);
        if(tab[c-W[i]][i+1] == 0) tab[c-W[i]][i+1] = KS(c-W[i], i+1);
        return max(tab[c][i+1], V[i] + tab[c-W[i]][i+1]);
    }
}*/

int knapSack(int W, int n)
{
   int i, w;
   //int K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

int main(){
    int t,c,ans,n;
    rd(t);
    while(t--){
        rd(c); rd(n);
        //int v[n],w[n];
        for(int i=0; i<n; i++){
            rd(wt[i]);
            rd(val[i]);
        }
    ans = knapSack(c,n);
    printf("Hey stupid robber, you can get %d.\n", ans);
    }
    return 0;
}

