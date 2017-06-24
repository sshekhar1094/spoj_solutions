#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
int tab[1050][1050]={0},n,v[1050];

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

int knapsack(int c){
    int i,w;
    for(int i=0; i<=n; i++)tab[0][c] = 0;
    for(int i=1; i<=n; i++){
        for(int w=0; w<=c; w++){
            if(i==1){
                if(v[i-1] <= w) tab[i][w] = v[i-1];
                else tab[i][w] = 0;
            }
            else{
                if(v[i-1]<=w) tab[i][w] = max( v[i-1] + tab[i-2][w-v[i-1]], tab[i-1][w] );
                else tab[i][w] = tab[i-1][w];
            }
        }
    }
    return tab[n][c];
}

int main(){
    int t,c,ans;
    rd(t);
    for(int i=1; i<=t; i++){
        rd(n); rd(c);
        for(int j=0; j<n; j++){ rd(v[j]);}
        //ans = KS(c, 0);
        ans = knapsack(c);
        printf("Scenario #%d: %d\n", i, ans);
    }
    return 0;
}



