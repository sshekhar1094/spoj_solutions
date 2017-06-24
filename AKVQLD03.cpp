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
int tree[10000000] = {0};
int arr[1000009] = {0};

//Lets get started
void Construct(int lo, int hi, int pos){
    if(lo == hi){
        tree[pos] = arr[lo];
        return;
    }
    int mid = (lo+hi)/2;
    Construct(lo, mid, 2*pos+1);
    Construct(mid+1, hi, 2*pos+2);
    tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}

int Query(int qlo, int qhi, int lo, int hi, int pos){
    if(qlo<=lo && qhi>=hi) return tree[pos];
    else if(qlo>hi || qhi<lo) return 0;
    int mid = (lo+hi)/2;
    return Query(qlo, qhi, lo, mid, 2*pos+1) + Query(qlo, qhi, mid+1, hi, 2*pos+2);
}

void Update(int pos, int lo, int hi, int ind, int val){
    //cout<<pos<<":"<<ind<<":"<<val<<endl;
    if(lo == hi){
        arr[ind] += val;
        tree[pos] += val;
        //printf("tree[%d]=%d, ind=%d\n", pos, tree[pos], ind);
        return;
    }
    int mid = (lo+hi)/2;
    if(lo<=ind && ind<=mid) Update(2*pos+1, lo, mid, ind, val);
    else Update(2*pos+2, mid+1, hi, ind, val);
    tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}

int main(int argc, char *argv[]){
    int n,q;
    rd(n); rd(q);
    int a,b;
    char str[10];
    for(int i=0; i<q; i++){
        scanf("%s", str);
        rd(a); rd(b);
        //cout<<a<<":"<<b<<endl;
        if(str[0] == 'f' ){
            int ans = Query(a-1, b-1, 0, n-1, 0);
            printf("%d\n", ans);
        }
        else{
            arr[a-1] += b;
            Update(0, 0, n-1, a-1, b);
        }
    }

    return 0;
}
