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
map<int, int> fst, snd;
int ar1[10009], ar2[10009];
int dp[10009][2];

//Lets get started
int func(int n1, int n2, bool ar, int ind){
    int a=_inf, b=_inf;

    if(ar == 0){
        if(ind>=n1) return 0;
        if(dp[ind][ar] != inf) return dp[ind][ar];
        a = func(n1,n2,0,ind+1) + ar1[ind];
        if(snd.find(ar1[ind]) != snd.end()){
            int i = snd[ar1[ind]];
            b = func(n1,n2,1,i+1) + ar1[ind];
        }
    }
    else{
        if(ind>=n2) return 0;
        if(dp[ind][ar] != inf) return dp[ind][ar];
        a = func(n1,n2,1,ind+1) + ar2[ind];
        if(fst.find(ar2[ind]) != fst.end()){
            int i = fst[ar2[ind]];
            b = func(n1,n2,0,i+1) + ar2[ind];
        }
    }
    dp[ind][ar] = max(a,b);
    //printf("arr=%d, ind=%d, a=%d, b=%d\n", ar, ind, a, b);
    return dp[ind][ar];
}

int main(int argc, char *argv[]){
    int n1, n2;
    while(1){
        rd(n1);
        if(n1==0) break;
        fst.clear();
        snd.clear();
        for(int i=0; i<n1; i++){
            rd(ar1[i]);
            fst[ar1[i]] = i;
        }
        rd(n2);
        for(int i=0; i<n2; i++){
            rd(ar2[i]);
            snd[ar2[i]] = i;
        }
        for(int i=0; i<max(n1,n2); i++){
            dp[i][0] = inf;
            dp[i][1] = inf;
        }
        int ans = max(func(n1, n2, 0, 0), func(n1, n2, 1, 0));
        printf("%d\n", ans);
    }
    return 0;
}
