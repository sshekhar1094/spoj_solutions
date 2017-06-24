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
#include <sstream>
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
ll up[109], lo[109];
ll dp[209][209];
#define mod 1000000007;

//Lets get started
ll rec(ll m, ll n, ll ind){
    if(ind==m && n==0) return 1;
    if(ind>=m) return 0;
    if(n<=0) return 0;
    if(dp[ind][n] != -1) return dp[ind][n];
    ll sum = 0;
    for(ll i=lo[ind]; i<=up[ind]; i++){
        sum = sum + rec(m, n-i, ind+1);
    }
    //printf("m=%d, n=%d, sum=%d\n", m, n, sum);
    dp[ind][n] = sum;
    return dp[ind][n];
}

int main(int argc, char *argv[]){
    ll m,n,t;
    rd(t);
    while(t--){
        rd(m); rd(n);
        for(ll i=0; i<m; i++){
            rd(lo[i]);
            rd(up[i]);
        }
        for(ll i=0; i<=m; i++){
            for(ll j=0; j<=n; j++)
                dp[i][j] = -1;
        }

        ll ans = rec(m, n, 0);
        /*for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++)
                printf("[%d,%d] = %d\n", i, j, dp[i][j]);
        }*/
        printf("%lld\n", ans);
    }
    return 0;
}
