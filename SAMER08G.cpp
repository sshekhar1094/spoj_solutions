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
vector< pii > v;
int ans[10000];

//Lets get started
int main(int argc, char *argv[]){
    pii p;
    int n, c, g;
    while(1){
        rd(n);
        if(n == 0) break;
        v.clear();
        for(int i=0; i<n; i++){
            ans[i] = -1;
            rd(c); rd(g);
            v.pb(mp(c, g));
        }
        int ind;
        bool flag=0;
        for(int i=0; i<n; i++){
            p = v[i];
            c = p.first;
            g = p.second;
            ind = i+g;
            if(ind<0 || ind>=n){
                flag=1;
                break;
            }
            if(ans[ind] != -1){
                flag = 1;
                break;
            }
            else{
                ans[ind] = c;
            }
        }
        if(flag == 0)
            for(int i=0; i<n; i++){
                if(ans[i] == -1){
                    flag = 1;
                    break;
                }
            }
        if(flag == 1){
            printf("-1\n");
            continue;
        }
        for(int i=0; i<n; i++) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
