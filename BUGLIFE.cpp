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
vector<int> adj[2016];
map<int, int> grp;

//Lets get started
int bfs(int ind, int n){
    grp[ind] = 1;
    queue<int> Q;
    Q.push(ind);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        int clr = grp[v], cr;
        for(int i=0; i<adj[v].size(); i++){
            int n2 = adj[v][i];
            if(clr == 1) cr = 2;
            else cr = 1;
            if(grp.find(n2) == grp.end()){
                Q.push(n2);
                grp[n2] = cr;
            }
            else{
                if(clr == grp[n2]) return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char *argv[]){
    int t,n,e;
    int n1,n2;
    rd(t);
    for(int z=0; z<t; z++){
        rd(n); rd(e);
        grp.clear();
        int ans = 1;
        for(int i=0; i<=n; i++) adj[i].clear();
        for(int i=0; i<e; i++){
            rd(n1); rd(n2);
            adj[n1].pb(n2);
            adj[n2].pb(n1);
        }
        for(int i=0; i<=n; i++){
            if(grp.find(i) == grp.end())
                ans = bfs(i, n);
            if(ans == 0) break;
        }
        printf("Scenario #%d:\n", z+1);
        if(ans == 1) printf("No suspicious bugs found!\n");
        else printf("Suspicious bugs found!\n");
    }

    return 0;
}
