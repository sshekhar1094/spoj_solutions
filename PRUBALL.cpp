#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
#include<limits.h>
using namespace std;
int eggFloor[53][1005];

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

int eggDrop(int n, int k)
{
    int res,i, j, x;
    for (i = 1; i <= n; i++){
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }
    for (j = 1; j <= k; j++)
        eggFloor[1][j] = j;
    for (i = 2; i <= n; i++){
        for (j = 2; j <= k; j++){
            eggFloor[i][j] = INT_MAX;
            for (x = 1; x <= j; x++){
                res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }

    return eggFloor[n][k];
}

int main(){
    int t,n,k,c;
    rd(t);
    while(t--){
        rd(c); rd(n); rd(k);
        n = eggDrop(n,k);
        printf("%d %d\n", c, n);
    }

    return 0;
}



