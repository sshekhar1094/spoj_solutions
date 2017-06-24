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
int dp[2016][2016];

//Let's get started
int func(int arr[], int lo, int hi, int age){
    if(lo > hi) return 0;
    if(dp[lo][hi] != -1) return dp[lo][hi];
    int b = age*arr[lo] + func(arr, lo+1, hi, age+1);
    int l = age*arr[hi] + func(arr, lo, hi-1, age+1);
    dp[lo][hi] =  max(l, b);
    return dp[lo][hi];
}

int main(int argc, char *argv[]){
    int n;
    rd(n);
    int arr[n];
    for(int i=0; i<n; i++) rd(arr[i]);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) dp[i][j] = -1;
    int ans = func(arr, 0, n-1, 1);
    cout<<ans<<endl;
    return 0;
}
