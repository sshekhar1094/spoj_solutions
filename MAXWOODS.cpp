#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <map>
#include <stdlib.h>
#include <string>
#include <queue>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <set>
#include <utility>
#include <stack>
#include <limits.h>
#include <functional>
using namespace std;

//Fast inputs
template <class T>
inline void rd(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-'); c=getchar());
	if(c=='-') {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar()) i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}

//Shortcuts
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define mp make_pair
#define inf INT_MAX
#define _inf INT_MIN

//Globals
char tab[201][201];
int dp[201][201][2];

//Lets get started
int func(int m, int n, int i, int j, bool dir){ //dir=1 means right
    if(i>=m || j>=n || i<0 || j<0) return 0;
    int x=0;
    if(tab[i][j] == '#') return 0;
    if(tab[i][j] == 'T') x=1;
    if(dp[i][j][dir] != -1) return dp[i][j][dir];
    if(dir)
        dp[i][j][dir] = x + max(func(m,n,i,j+1,1), func(m,n,i+1,j,0) );
    else dp[i][j][dir] = x + max(func(m,n,i,j-1,0), func(m,n,i+1,j,1));
    return dp[i][j][dir];
}

int main(int argc, char *argv[]){
    int t,m,n;
    rd(t);
    while(t--){
        rd(m); rd(n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>tab[i][j];
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }
        int ans;
        if(tab[0][0] == '#') ans = 0;
        else ans = func(m,n,0,0,1);
        printf("%d\n", ans);
    }
    return 0;
}
