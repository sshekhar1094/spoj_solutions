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
#include <unordered_map>
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
int mat[255][255];
bool vis[255][255];
map<int, int> sz;

//Lets get started
void bfs(int i, int j, int m, int n){
    queue< pii > Q;
    Q.push(mp(i, j));
    vis[i][j] = 1;
    int cur=0;
    while(!Q.empty()){
        pii p = Q.front();
        Q.pop();
        cur++;
        i = p.first;
        j = p.second;
        if(i-1>=0 && vis[i-1][j]==0 && mat[i-1][j]==1) Q.push(mp(i-1, j)), vis[i-1][j] = 1;
        if(j-1>=0 && vis[i][j-1]==0 && mat[i][j-1]==1) Q.push(mp(i, j-1)), vis[i][j-1] = 1;
        if(i+1<n && vis[i+1][j]==0 && mat[i+1][j]==1) Q.push(mp(i+1, j)), vis[i+1][j] = 1;
        if(j+1<m && vis[i][j+1]==0 && mat[i][j+1]==1) Q.push(mp(i, j+1)), vis[i][j+1] = 1;




    }
    sz[cur]++;
}

int main(int argc, char *argv[]){
    int n, m;
    while(1){
        rd(n); rd(m);
        memset(vis, 0, sizeof(vis));
        memset(mat, 0, sizeof(mat));
        sz.clear();
        if(n==0 && m==0) break;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                rd(mat[i][j]);

        int sec=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1 && vis[i][j]==0){
                    sec++;
                    bfs(i, j, m, n);
                }
            }
        }

        printf("%d\n", sec);
        map<int, int> :: iterator it;
        for(it = sz.begin(); it!=sz.end(); it++){
            printf("%d %d\n", (*it).first, (*it).second);
        }
    }

    return 0;
}
