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

int main(int argc, char *argv[]){
    ll x,y,z;
    int t;
    rd(t);
    while(t--){
        rd(x); rd(y); rd(z);
        long long ans;
        long long rt = x*x + y*y + 2*y*z;
        ll d = sqrt(rt);
        if(d*d != rt) printf("Not this time.\n", d, rt,x,y,z);
        else{
            ll num = 2*z*x + 2*z*d;
            ll den = 2*y + 4*z;
            if(num%den != 0) printf("Not this time.\n");
            else{
                ans = num/den;
                if(ans>=0 && ans<=x) printf("%lld\n", ans);
                else printf("Not this time.");
            }
        }
    }

    return 0;
}
