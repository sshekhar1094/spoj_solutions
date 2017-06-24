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
vector<pii > adj[1009][1009];
bool vis[1009][1009];

//Lets get started
void bfs(int vi, int vj){
    pii p = mp(vi, vj);
    vis[vi][vj] = 1;
    queue<pii > Q;
    Q.push(p);
    while(!Q.empty()){
        p = Q.front();
        //printf("(%d,%d), ", p.first, p.second);
        Q.pop();
        for(int i=0; i<adj[p.first][p.second].size(); i++){
            pii p2 = adj[p.first][p.second][i];
            if(!vis[p2.first][p2.second]){
                Q.push(p2);
                vis[p2.first][p2.second] = 1;
            }
        }
    }
}

int main(int argc, char *argv[]){
    int m,n;
    rd(m); rd(n);
    char c;
    string str;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            adj[i][j].clear();
    for(int i=0; i<m; i++){
        cin>>str;
        for(int j=0; j<n; j++){
            c = str[j];
            vis[i][j] = 0;
            pii p1 = mp(i, j), p2;
            if(c == 'N') p2 = mp(i-1, j);
            else if(c == 'S') p2 = mp(i+1, j);
            else if(c == 'E') p2 = mp(i, j+1);
            else if(c == 'W') p2 = mp(i, j-1);
            adj[i][j].pb(p2);
            adj[p2.first][p2.second].pb(p1);
        }
    }

    int ct = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]){
                    ct++;
                    bfs(i, j);
                    //cout<<endl;
                }
            }
        }
        printf("%d\n", ct);

    return 0;
}
