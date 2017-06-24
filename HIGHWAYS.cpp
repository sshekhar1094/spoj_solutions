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
vector< pii > adj[100009];
long long ans[100009];
set< pii > heap;

//Lets get started
int main(int argc, char *argv[]){
    int n,t,e,src,dst;
    int n1,n2,w;
    pii p;
    set< pair<int, int> > :: iterator it;
    rd(t);

    while(t--){
        rd(n); rd(e);
        rd(src); rd(dst);
        heap.clear();
        for(int i=1; i<n+1; i++){
            adj[i].clear();
            ans[i] = inf;
        }

        for(int i=0; i<e; i++){
            rd(n1); rd(n2); rd(w);
            ans[n1] = inf;
            ans[n2] = inf;
            adj[n1].pb(mp(n2,w));
            adj[n2].pb(mp(n1,w));
        }

        ans[src] = 0;
        for(int i=1; i<n+1; i++)
            heap.insert(mp(ans[i], i));

        while(!heap.empty()){
            it = heap.begin();
            p = *it;
            n1 = p.second;
            if(p.first == inf) break;
            heap.erase(p);
            for(int i=0; i<adj[n1].size(); i++){
                n2 = adj[n1][i].first;
                w = adj[n1][i].second;
                if(ans[n1]!=inf && ans[n2] > ans[n1] + w){
                    p = mp(ans[n2], n2);
                    heap.erase(p);
                    ans[n2] = ans[n1] + w;
                    heap.insert(mp(ans[n2], n2));
                }
            }
        }
        //for(int i=1; i<n+1; i++) cout<<i<<":"<<ans[i]<<endl;
        if(ans[dst] == inf) printf("NONE\n");
        else printf("%lld\n", ans[dst]);
    }

    return 0;
}
