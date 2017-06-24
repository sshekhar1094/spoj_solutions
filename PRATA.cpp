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
//#include <unordered_map>
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

//Lets get started
int Time(int a, int n){
    return ((a*n*(n+1))/2);
}

int prata(int a, int n){
    return ( sqrt(a*a+8*a*n)-a )/(2*a);
}

int main(int argc, char *argv[]){
    int p, ck, rank[59], t;
    rd(t);
    while(t--){
        rd(p); rd(ck);
        int ans = 0;
        for(int i=0; i<ck; i++) rd(rank[i]);
        sort(rank, rank + ck);
        int T = Time(rank[ck-1], p);
        int l=1, h=T;
        int mid = (l+h)/2, tot;
        while(l<=h){
            tot = 0;
            mid = (l+h)/2;
            //cout<<l<<":"<<h<<":"<<mid;
            for(int i=0; i<ck; i++){
                tot = tot + prata(rank[i], mid);
                if(tot > p) break;
            }
            if(tot>=p){
                ans = mid;
                h = mid-1;
            }
            else l = mid+1;
            //cout<<":"<<tot<<endl;
            //getchar();
        }
        printf("%d\n", ans);
    }

    return 0;
}
