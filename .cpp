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
#include <sstream>
#include <list>
#include <unordered_map>
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
int bef[10009];
list<int> lst;

//Lets get started

int main(int argc, char *argv[]){
    int t, n, tmp;
    rd(t);
    while(t--){
        rd(n);
        v.clear();
        lst.clear();
        list<int> :: iterator it;
        for(int i=0; i<n; i++){
            rd(tmp);
            v.pb(mp(tmp, i));
        }
        for(int i=0; i<n; i++) rd(bef[i]);

        sort(v.rbegin(), v.rend());
        lst.push_back(v[0].first);
        for(int i=1; i<n; i++){
            it = lst.begin();
            int h = v[i].first, ind = v[i].second;
            int bf = bef[ind];
            advance(it, bf);
            lst.insert(it, h);
        }

        for(it = lst.begin(); it!=lst.end(); it++) printf("%d ", *it);
        printf("\n");
    }

    return 0;
}
