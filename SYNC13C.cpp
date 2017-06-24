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
bool dp[10009];

//Lets get started
int main(int argc, char *argv[]){
    int t,c1,c2;
    bool ans = 1;
    dp[1]=0; dp[2]=1; dp[3]=0;
    for(int i=4; i<10009; i++){
        dp[i] = 0;
        for(int j=1; j<=i/2; j++){
            if(dp[j]==0 && dp[i-j]==0){
                dp[i] = 1;
                break;
            }
        }
    }

    rd(t);
    while(t--){
        rd(c1); rd(c2);
        ans = dp[c1] || dp[c2];
        if(ans) printf("Suresh\n");
        else printf("Ramesh\n");
    }

    return 0;
}
