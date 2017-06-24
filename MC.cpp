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
int dp[1009][1009];

//Lets get started
int lcs(string s1, string s2){
    int n1 = s1.size(), n2=s2.size();
    for(int i=0; i<n1; i++) dp[i][0] = 0;
    for(int j=0; j<n2; j++) dp[0][j] = 0;
    for(int i=1; i<n1+1; i++){
        for(int j=1; j<n2+1; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    /*for(int i=0; i<n1+1; i++){
        for(int j=0; j<n2+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return dp[n1][n2];
}

int main(int argc, char *argv[]){
    string s1, s2;
    while(1){
        cin>>s1;
        if(s1[0] == '#') break;
        cin>>s2;
        int n1=s1.size(), n2=s2.size();
        int l = lcs(s1, s2);
        int ans = (n1-l)*15 + (n2-l)*30;
        printf("%d\n",ans);
    }

    return 0;
}
