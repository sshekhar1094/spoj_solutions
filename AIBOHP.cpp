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
#include <unordered_map>
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
int dp[6109][6109];

//Lets get started
int lcs(string s1, string s2){
    int n = s1.size();
    for(int i=0; i<n; i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main(int argc, char *argv[]){
    int t;
    string str;
    rd(t);
    while(t--){
        cin>>str;
        int n = str.size();
        string rev = str;
        reverse(str.begin(), str.end());
        n = n - lcs(str, rev);
        //cout<<lcs(str, rev)<<endl;
        printf("%d\n", n);
    }
    return 0;
}
