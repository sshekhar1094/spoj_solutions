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

//Lets get started
int main(int argc, char *argv[]){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0; i<n; i++) rd(arr[i]);
    int dp[5009] = {0};
    dp[0] = 1;
    int mx;
    for(int i=1; i<n; i++){
        mx = 0;
        for(int j=0; j<i; j++){
            if(abs(arr[i]) > abs(arr[j])){
                if(arr[i]>0 && arr[j]<0) mx = max(mx, dp[j]);
                else if(arr[i]<0 && arr[j]>0) mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx+1;
    }
    int ans=0;
    for(int i=0; i<n; i++) ans = max(ans, dp[i]);
    cout<<ans<<endl;

    return 0;
}
