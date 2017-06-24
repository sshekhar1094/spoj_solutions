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

//Globals
int dp[2016][2];

//Let's get started
int func(int len[], int bdt[], int ind, int n, bool lst){
    if(ind >= n) return 0;
    if(dp[ind][lst] != -1) return dp[ind][lst];
    int last;
    if(lst == 0) last = bdt[ind-1];
    else last = len[ind-1];
    int l1 = abs(last - len[ind]) + bdt[ind] + func(len, bdt, ind+1, n, 1);
    int l2 = abs(last - bdt[ind]) + len[ind] + func(len, bdt, ind+1, n, 0);
    dp[ind][lst] = max(l1, l2);
    return dp[ind][lst];
}

int main(int argc, char *argv[]){
    int n;
    rd(n);
    int len[n], bdt[n], last=0;
    for(int i=0; i<n; i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
        rd(len[i]);
        rd(bdt[i]);
    }
    int l1 = bdt[0] + func(len, bdt, 1, n, 1);
    int l2 = len[0] + func(len, bdt, 1, n, 0);

    int ans = max(l1, l2);
    printf("%d\n", ans);
    return 0;
}
