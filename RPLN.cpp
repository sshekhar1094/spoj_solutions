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

//Globals
int tree[400009], arr[100009];

//Let's get started
void construct(int low, int high, int pos){
    if(low == high){
        tree[pos] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    construct(low, mid, 2*pos+1);
    construct(mid+1, high, 2*pos+2);
    tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
}

int query(int qlow, int qhigh, int low, int high, int pos){
    if(low>high || low>qhigh || high<qlow) return INT_MAX;
    if(qlow<=low && high<=qhigh) return tree[pos];
    int mid = (low+high)/2;
    return min(query(qlow, qhigh, low, mid, 2*pos+1), query(qlow, qhigh, mid+1, high, 2*pos+2));
}

int main(){
    int t,q,n,a,b,ans;
    rd(t);
    for(int z=0; z<t; z++){
        rd(n); rd(q);
        printf("Scenario #%d:\n", z+1);
        for(int i=0; i<n; i++) rd(arr[i]);
        construct(0, n-1, 0);
        while(q--){
            rd(a); rd(b);
            a--; b--;
            ans = query(a, b, 0, n-1, 0);
            printf("%d\n", ans);
        }
    }
    return 0;
}
