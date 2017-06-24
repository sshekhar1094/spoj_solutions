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
unordered_map<int, int> m;
int arr[100009];

//Lets get started
int main(int argc, char *argv[]){
    int t,n,x;
    rd(t);
    for(int k=0; k<t; k++){
        rd(x); rd(n);
        m.clear();
        ll ct=0;
        for(int i=0; i<n ; i++){
            rd(arr[i]);
            int y = x - arr[i];
            if(m.find(y) != m.end()){
                ct = ct + m[y];
            }
            m[arr[i]]++;
        }
        printf("%d. %lld\n", k+1, ct);
    }

    return 0;
}
