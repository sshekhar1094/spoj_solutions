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
typedef pair< int ,int > pii;
#define pb push_back
#define mp make_pair
#define inf 99999999
#define _inf INT_MIN

//Globals
char mat[109][109];
int ei,ej;
int dis[109][109];

//Lets get started
void bfs(int h, int w, int si, int sj){
    queue<pii > Q;
    pii p;
    Q.push(mp(si, sj));
    dis[si][sj] = 0;
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        int i,j,u,v;
        i = p.first;
        j = p.second;
        u = i-1;
        while(u>=0 && mat[u][j]!='*'){
            if(dis[u][j] > dis[i][j]+1){
                dis[u][j] = dis[i][j]+1;
                Q.push(mp(u,j));
            }
            u--;
        }
        u = i+1;
        while(u<h && mat[u][j]!='*'){
            if(dis[u][j] > dis[i][j]+1){
                dis[u][j] = dis[i][j]+1;
                Q.push(mp(u,j));
            }
            u++;
        }
        v = j-1;
        while(v>=0 && mat[i][v]!='*'){
            if(dis[i][v] > dis[i][j]+1){
                dis[i][v] = dis[i][j]+1;
                Q.push(mp(i,v));
            }
            v--;
        }
        v = j+1;
        while(v<w && mat[i][v]!='*'){
            if(dis[i][v] > dis[i][j]+1){
                dis[i][v] = dis[i][j]+1;
                Q.push(mp(i,v));
            }
            v++;
        }
    }
}

void init(int h, int w){
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++) dis[i][j] = inf;
}

void Print(int h, int w){
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cout<<dis[i][j]<<" ";
        cout<<endl;
    }
}

int main(int argc, char *argv[]){
    int h,w;
    rd(w); rd(h);
    init(h,w);
    char str[109];
    int si=-1, sj;
    for(int i=0; i<h; i++){
        scanf("%s", str);
        for(int j=0; j<w; j++){
            mat[i][j] = str[j];
            if(str[j] == 'C'){
                if(si==-1){
                    si = i;
                    sj = j;
                }
                else{
                    ei = i;
                    ej = j;
                }
            }
        }
    }
    bfs(h,w,si,sj);
    //Print(h,w);
    int ans = dis[ei][ej] - 1;
    printf("%d\n", ans);
    return 0;
}
