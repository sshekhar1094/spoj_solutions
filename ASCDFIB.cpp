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
#define mod 100000
int fib[1200000];
int ct[1200000];

//Lets get started

int main(int argc, char *argv[]){
    //memset(arr, 0, sizeof(int)*1200000);
    fib[1]=0; fib[2]=1;
    for(int i=3; i<1200000; i++){
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] = fib[i] % mod;
    }
    //cout<<"done\n";
    int t,l,r;
    rd(t);
    for(int z=0; z<t; z++){
        rd(l); rd(r);
        r = l+r;
        printf("Case %d:", z+1);
        memset(ct, 0, sizeof(int)*1200000);
        for(int i=l; i<=r; i++){
            ct[fib[i]]++;
            //cout<<fib[i]<<":";
        }
        int k = 0;
        for(int i=0; i<100000 && k<100; i++){
            while(ct[i]!=0 && k<100){
                printf(" %d", i);
                k++;
                ct[i]--;
            }
        }
        printf("\n");
    }

    return 0;
}
