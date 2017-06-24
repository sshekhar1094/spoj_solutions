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
int mat[51][51];
int dp[51][51][260];

//Lets get started
int func(int m, int n, int i, int j, int c){
    if(i<0 || j<0 || i>=m || j>=n) return 0;
    int ans = 1;
    if(dp[i][j][c] != -1) return dp[i][j][c];
    if(mat[i][j] == c+1){
        int ch = mat[i][j];

        ans = max(ans, func(m, n, i, j-1, ch)+1);
        ans = max(ans, func(m, n, i, j+1, ch)+1);
        ans = max(ans, func(m, n, i-1, j, ch)+1);
        ans = max(ans, func(m, n, i+1, j, ch)+1);
        ans = max(ans, func(m, n, i-1, j-1, ch)+1);
        ans = max(ans, func(m, n, i-1, j+1, ch)+1);
        ans = max(ans, func(m, n, i+1, j-1, ch)+1);
        ans = max(ans, func(m, n, i+1, j+1, ch)+1);
        //printf("%c, %d, %d : %d\n", ch, i, j, ans);
    }
    else ans = 0;
    dp[i][j][c] = ans;
    return dp[i][j][c];

}

int main(int argc, char *argv[]){
    int m,n,c;
    int t=0;
    string str;
    while(1){
        t++;
        rd(m); rd(n);
        if(m==0 && n==0) break;
        for(int i=0; i<m; i++){
            cin>>str;
            for(int j=0; j<n; j++){
                mat[i][j] = (int)(str[j]);
                for(int k=0; k<260; k++) dp[i][j][k] = -1;
            }
        }

        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                c = mat[i][j];
                if(c != 65) continue;
                ans = max(ans, func(m, n, i, j-1, c)+1);
                ans = max(ans, func(m, n, i, j+1, c)+1);
                ans = max(ans, func(m, n, i-1, j, c)+1);
                ans = max(ans, func(m, n, i+1, j, c)+1);
                ans = max(ans, func(m, n, i-1, j-1, c)+1);
                ans = max(ans, func(m, n, i-1, j+1, c)+1);
                ans = max(ans, func(m, n, i+1, j-1, c)+1);
                ans = max(ans, func(m, n, i+1, j+1, c)+1);
            }
        }
        printf("Case %d: %d\n", t, ans);
        //cout<<dp[3][1]['A']<<":"<<dp[3][1]['B'];
    }

    return 0;
}
