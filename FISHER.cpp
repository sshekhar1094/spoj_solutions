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
//#include <unordered_map>
#include <list>
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
ll tym[55][55], tol[55][55];
pair<ll, ll> dp[55][55];
#define mx 9999

//Lets get started
pair<ll, ll> func(ll curr, ll dst, ll tm){
    if(tm < 0) return mp(inf, inf);
    if(curr == dst) return mp(0, 0);
    if(dp[curr][tm].first != -1) return dp[curr][tm];
    pair<ll, ll> nxt = mp(inf, inf);   //pair of amt, tym
    pair<ll, ll> ans = nxt;
    for(int i=0; i<=dst; i++){
        if(i == curr) continue;
        nxt = func(i, dst, tm - tym[curr][i]);
        if(nxt.first + tol[curr][i] < ans.first){
            ans.first = nxt.first + tol[curr][i];
            ans.second = nxt.second + tym[curr][i];
        }
    }
    dp[curr][tm] = ans;
    return ans;
}

int main(int argc, char *argv[]){
    ll n,t;
    while(1){
        scanf("%lld %lld\n", &n, &t);
        if(n==0 && t==0) break;
        for(int i=0; i<55; i++){
            for(int j=0; j<1009; j++){
                dp[i][j].first = -1;
                dp[i][j].second = -1;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%lld", &tym[i][j]);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%lld", &tol[i][j]);
            }
        }
        pair<ll, ll> ans = func(0, n-1, t);
        printf("%lld %lld\n", ans.first, ans.second);
    }

    return 0;
}
