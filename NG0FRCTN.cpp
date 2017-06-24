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

int main(int argc, char *argv[]){
    //fill();
    int nu, den;
    ll n;
    vector<int> st;
    while(1){
        st.clear();
        scanf("%lld", &n);
        if(n == 0) break;
        ll t = n;
        while(t > 1){
            st.pb(t%2);
            t = t/2;
        }
        nu = 1;
        den = 1;
        int y,d;
        while(st.size()){
            int x = st.back();
            st.pop_back();
            if(x == 1){
                y = nu + den;
                d = den;
                //t = t*2 + 1;
            }
            else{
                y = nu;
                d = den + nu;
                //t = t*2;
            }
            nu = y;
            den = d;
        }
        //cout<<t;
        printf("%d/%d\n", nu, den);
    }

    return 0;
}
