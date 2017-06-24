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
vector<int> adj[10009];
bool vis[10009];
int dis[10009];

//Let's get started
void clear(int n, bool lst){
    for(int i=1; i<n+1; i++){
        if(lst == 1) adj[i].clear();
        dis[i] = 0;
        vis[i] = 0;
    }
}

int bfs(int ind, int n){
    queue<int> Q;
    vis[ind] = 1;
    dis[ind] = 0;
    Q.push(ind);
    while(!Q.empty()){
        int n1 = Q.front(), n2;
        Q.pop();
        for(int i=0; i<adj[n1].size(); i++){
            n2 = adj[n1][i];
            //printf("%d pushing %d\n", n1, n2);
            if(!vis[n2]){
                Q.push(n2);
                dis[n2] = dis[n1] + 1;
                vis[n2] = 1;
            }
        }
    }

    int mx = -1, mxi;
    for(int i=1; i<n+1; i++){
        if(dis[i] > mx){
            mx = dis[i];
            mxi = i;
        }
    }
    return mxi;
}


int main(int argc, char *argv[]){
    int n, n1, n2;
    rd(n);
    clear(n, 1);
    for(int i=0; i<n-1; i++){
        rd(n1); rd(n2);
        adj[n1].pb(n2);
        adj[n2].pb(n1);
    }
    int start = bfs(1, n);
    clear(n, 0);
    int ans = bfs(start, n);
    printf("%d\n", dis[ans]);
    return 0;
}
