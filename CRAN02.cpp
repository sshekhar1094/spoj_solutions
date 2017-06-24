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
ll arr[1000009], sum[1000009];
map<int, int> m;

//Lets get started
int main(int argc, char *argv[]){
    int n,t;
    rd(t);
    while(t--){
        rd(n);
        m.clear();
        for(int i=0; i<n; i++) rd(arr[i]);
        sum[0] = arr[0];
        for(int i=1; i<n; i++)
            sum[i] = sum[i-1] + arr[i];
        ll ct=0, pr=0;
        m[0]++;
        for(int i=0; i<n; i++){
            ct = ct + m[sum[i]];
            m[sum[i]]++;
        }
        cout<<ct<<endl;
    }
    return 0;
}
