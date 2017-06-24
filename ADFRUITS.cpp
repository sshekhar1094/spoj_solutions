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
#include <unordered_map>
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
int dp[109][109], tab[109][109];
string lcs;

//Lets get started
void LCS(char s1[], int i, int j){
    if(i==0 || j==0) return;
    if(tab[i][j] == 2){
        LCS(s1, i-1, j-1);
        lcs = lcs + s1[i-1];
    }
    else if(tab[i][j] == 0) LCS(s1, i-1, j);
    else LCS(s1, i, j-1);
}

void func(char s1[], char s2[]){
    int len1 = strlen(s1), len2=strlen(s2);
    for(int i=0; i<=len1; i++) dp[i][0] = 0;
    for(int i=0; i<=len2; i++) dp[0][i] = 0;
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                tab[i][j] = 2;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                tab[i][j] = 0;
            }
            else{
                dp[i][j] = dp[i][j-1];
                tab[i][j] = 1;
            }
        }
    }
    LCS(s1, len1, len2);
}

int main(int argc, char *argv[]){
    char s1[109], s2[109];
    string ans;
    while(scanf("%s %s", &s1, &s2) == 2){
        lcs.clear();
        ans.clear();
        int len1=strlen(s1), len2=strlen(s2);
        func( s1,  s2);
        //cout<<lcs;
        int l=0, r=0, k=lcs.size();
        for(int i=0; i<k; i++){
            char c = lcs[i];
            while(s1[l]!=c && l<len1){
                ans = ans + s1[l];
                l++;
            }
            while(s2[r]!=c && r<len2){
                ans = ans + s2[r];
                r++;
            }
            ans = ans + c;
            l++;
            r++;
        }
        while(l<len1){
            ans = ans + s1[l];
            l++;
        }
        while(r<len2){
            ans = ans + s2[r];
            r++;
        }
        cout<<ans<<endl;
    }

    return 0;
}
