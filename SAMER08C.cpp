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
int arr[100009], row[100009], dp[100009];

//Lets get started
int main(int argc, char *argv[]){
    int m, n;
    while(1){
        rd(m); rd(n);
        if(m==0 && n==0) break;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                rd(arr[j]);
                dp[j] = 0;
            }
            dp[0] = arr[0];
            if(n>1) dp[1] = max(dp[0], arr[1]);
            for(int j=2; j<n; j++)
                dp[j] = max(dp[j-1], dp[j-2] + arr[j]);
            row[i] = dp[n-1];
            //cout<<i<<":"<<row[i]<<endl;
        }

        for(int i=0; i<m; i++) dp[i] = 0;
        dp[0] = row[0];
        if(m>1) dp[1] = max(dp[0], row[1]);
        for(int i=2; i<m; i++)
            dp[i] = max(dp[i-1], dp[i-2] + row[i]);
        printf("%d\n", dp[m-1]);
    }

    return 0;
}
