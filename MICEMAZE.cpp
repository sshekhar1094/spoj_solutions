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
vector<pii > adj[109];
set<pii > heap;
int dis[109];

//Let's get started

int main(){
    int n,src,t,e;
    int v1,v2,w;
    pii p;
    rd(n); rd(src); rd(t); rd(e);
    for(int i=1; i<n+1; i++){
        adj[i].clear();
        dis[i] = inf;
    }
    for(int i=0; i<e; i++){
        rd(v1); rd(v2); rd(w);
        adj[v2].pb(mp(v1, w));
    }

    dis[src] = 0;
    for(int i=1; i<n+1; i++) heap.insert(mp(dis[i], i));
    while(!heap.empty()){
        p = *(heap.begin());
        v1 = p.second;
        w = p.first;
        if(w == inf) break;
        heap.erase(p);
        for(int i=0; i<adj[v1].size(); i++){
            v2 = adj[v1][i].first;
            w = adj[v1][i].second;
            if(dis[v1]!=inf && dis[v2]>dis[v1]+w){
                heap.erase(mp(dis[v2], v2));
                dis[v2] = dis[v1]+w;
                heap.insert(mp(dis[v2], v2));
            }
        }
    }

    int ct = 0;
    for(int i=1; i<n+1; i++)
        if(dis[i] <= t) ct++;
    printf("%d\n", ct);

    return 0;
}
