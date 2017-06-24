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
int a[1000009], b[1000009];

//Lets get started
int main(int argc, char *argv[]){
    int n;
    rd(n);
    for(int i=0; i<n; i++) rd(a[i]);
    for(int i=0; i<n; i++) rd(b[i]);
    sort(a, a+n);
    sort(b, b+n);
    int l=0, r=0;
    int ct = 0;
    while(l<n && r<n){
        while(b[r] <= a[l]){
            r++;
            if(r>=n) break;
        }
        if(r>=n) break;
        if(a[l] < b[r]){
            ct++;
            l++;
            r++;
        }
    }
    printf("%d\n", ct);

    return 0;
}
