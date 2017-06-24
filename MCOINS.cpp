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

//Globals
bool dp[1000009] = {0};

//Let's get started

int main(int argc, char *argv[]){
    int k,l,m,n;
    rd(k); rd(l); rd(m);
    dp[1] = 1; dp[k]=1; dp[l]=1;
    for(int i=2; i<1000009; i++){
        if(dp[i] == 0){
            if(dp[i-1] == 0) dp[i] = 1;
            else if(i>k && dp[i-k]==0) dp[i]=1;
            else if(i>l && dp[i-l]==0) dp[i]=1;
        }
    }
    int arr[m];
    while(m--){
        rd(n);
        if(dp[n] == 1) cout<<"A";
        else cout<<"B";
    }

    return 0;
}
