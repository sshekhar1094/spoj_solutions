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
int ass[10009], cap[10009];
unsigned int dp[10009][6000] = {0};

//Lets get started
int func(int n, int na, int nc, int ind){
    if(na>n/2 || nc>n/2) return inf;
    if(ind >= n) return 0;
    if(nc > na) return inf;
    if(dp[ind][na] != 0) return dp[ind][na];
    unsigned int t1 = func(n, na+1, nc, ind+1)+ass[ind];
    unsigned int t2 = func(n, na, nc+1, ind+1)+cap[ind];
    dp[ind][na] = min(t1, t2);
    return dp[ind][na];
}

int main(int argc, char *argv[]){
    int n, na, nc;
    rd(n);
    for(int i=0; i<n; i++){
        rd(cap[i]);
        rd(ass[i]);
    }
    int ans = inf;
    ans = func(n, 1, 0, 1) + ass[0];
    printf("%d\n", ans);

    return 0;
}
