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
using namespace std;
int tree[200009]={0}, lazy[200009]={0};

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

//Let's get started
void updateRange(int qlow, int qhigh, int low, int high, int pos){
    if(lazy[pos] != 0){
        tree[pos] = high - low + 1 - tree[pos];
        if(low != high){
            lazy[2*pos + 1] = !lazy[2*pos + 1];
            lazy[2*pos + 2] = !lazy[2*pos + 2];
        }
        lazy[pos] = 0;
    }
    if(low > high || low>qhigh || high < qlow) return;
    if(low >= qlow && high<=qhigh){
        tree[pos] = high - low + 1 - tree[pos];
        if(low != high){
            lazy[2*pos + 1] = !lazy[2*pos + 1];
            lazy[2*pos + 2] = !lazy[2*pos + 2];
        }
        return;
    }
    int mid = (low + high)/2;
    updateRange(qlow, qhigh, low, mid, 2*pos + 1);
    updateRange(qlow, qhigh, mid+1, high, 2*pos+2);
    tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}

int query(int qlow, int qhigh, int low, int high, int pos){
    if(low>high || low>qhigh || high<qlow) return 0;
    if(lazy[pos] != 0){
        tree[pos] = high - low + 1 - tree[pos];
        if(low != high){
            lazy[2*pos + 1] = !lazy[2*pos + 1];
            lazy[2*pos + 2] = !lazy[2*pos + 2];
        }
        lazy[pos] = 0;
    }
    if(low>=qlow && high<=qhigh) return tree[pos];
    int mid = (low+high)/2;
    return query(qlow, qhigh, low, mid, 2*pos+1) + query(qlow, qhigh, mid+1, high, 2*pos+2);
}

int main(){
    int n,m,t,a,b;
    rd(n); rd(m);
    while(m--){
        rd(t); rd(a); rd(b);
        if(t == 0){
            updateRange(a-1, b-1, 0, n-1, 0);
        }
        else{
            int ans = query(a-1, b-1, 0, n-1, 0);
            printf("%d\n", ans);
        }
    }
    return 0;
}
