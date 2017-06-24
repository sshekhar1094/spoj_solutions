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
//#include <unordered_map>
#include <list>
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
int arr[100009];

//Lets get started

int main(int argc, char *argv[]){
    int t, n, c;
    rd(t);
    while(t--){
        rd(n); rd(c);
        for(int i=0; i<n; i++) rd(arr[i]);
        sort(arr, arr+n);
        int l=inf, r;
        for(int i=1; i<n; i++) l = min(arr[i]-arr[i-1], l);
        r = arr[n-1] - arr[0];
        int mid, ans;
        while(l<r){
            mid = (l+r)/2;
            int ct=1, last = arr[0];
            for(int i=1; i<n; i++){
                if(arr[i]-last >= mid){
                    ct++;
                    last = arr[i];
                }
            }
            if(ct >= c){
                ans = mid;
                l = mid+1;
            }
            else r = mid;

        }
        printf("%d\n", ans);
    }


    return 0;
}
