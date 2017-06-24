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
bool vis[100009];
vector<int > adj[100009];

//Lets get started
void dfs(int v){
    vis[v] = 1;
    //cout<<v<<" ";
    for(int i=0; i<adj[v].size(); i++){
        int n = adj[v][i];
        if(!vis[n]) dfs(n);
    }
}

int main(int argc, char *argv[]){
    int t,n,e;
    int n1,n2;
    rd(t);
    while(t--){
        rd(n); rd(e);
        for(int i=0; i<n; i++){
            adj[i].clear();
            vis[i] = 0;
        }
        for(int i=0; i<e; i++){
            rd(n1); rd(n2);
            adj[n1].pb(n2);
            adj[n2].pb(n1);
        }

        int ct=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ct++;
                dfs(i);
                //cout<<endl;
            }
        }
        printf("%d\n", ct);

    }

    return 0;
}
