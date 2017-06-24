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
int dp[1009] = {0};

//Lets get started
int func(int n){
    int mn = inf;
    if(n<=3) return n;
    if(dp[n] != 0) return dp[n];
    for(int i=1; i<33; i++){
        if(i*i > n) break;
        mn = min(mn, func(n - i*i) + 1);
    }
    dp[n]  = mn;
    return dp[n];
}

int main(int argc, char *argv[]){
    //cout<<32 - __builtin_clz (n);
    dp[1]=1; dp[2]=2; dp[3]=3;
    for(int i=4; i<1009; i++){
        dp[i] = func(i);
        //if(i>=30 && i<=40) cout<<i<<":"<<dp[i]<<endl;
    }
    int t, n;
    rd(t);
    while(t--){
        rd(n);
        printf("%d\n", dp[n]);
    }

    return 0;
}
