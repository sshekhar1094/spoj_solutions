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
int arr[100009];
ll dp[100009];

//Lets get started
ll func(int n, int ind){
    if(ind >= n) return 0;
    if(dp[ind] != -1) return dp[ind];
    ll ans, t1=0, t2=0, t3=0;
    t1 = func(n, ind+2) + arr[ind];
    if(n-ind >= 2) t2 = func(n, ind+4) + arr[ind] + arr[ind+1];
    if(n-ind >= 3) t3 = func(n, ind+6) + arr[ind] + arr[ind+1] + arr[ind+2];
    ans = max(t1, max(t2, t3));
    dp[ind] = ans;
    return dp[ind];
}

int main(int argc, char *argv[]){
    int t,n;
    rd(t);
    while(t--){
        rd(n);
        for(int i=0; i<n; i++) rd(arr[i]);
        if(n<=3){
            int sum=0;
            for(int i=0; i<n; i++) sum = sum + arr[i];
            printf("%d\n", sum);
            continue;
        }
        for(int i=0; i<=n; i++) dp[i] = -1;
        ll ans = max(func(n,2)+arr[0], max(func(n, 4)+arr[0]+arr[1], func(n,6)+arr[0]+arr[1]+arr[2]));
        printf("%lld\n", ans);
    }

    return 0;
}
