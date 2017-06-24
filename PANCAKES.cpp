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
#define inf 99999999
#define _inf INT_MIN

//Globals


//Lets get started

int main(int argc, char *argv[]){
    int ingred[53], recipe[100][53];
    int n,r;
    while(1){
        rd(n); rd(r);
        if(n+r == 0) break;
        for(int i=0; i<n; i++){
            rd(ingred[i]);
            ingred[i] *= 10;
        }
        int ansr, mx=-1;
        for(int i=0; i<r; i++)
            for(int j=0; j<n; j++)
                rd(recipe[i][j]);

        for(int i=0; i<r; i++){
            int m = inf;
            for(int j=0; j<n; j++){
                if(recipe[i][j] == 0) continue;
                m = min(m, ingred[j]/recipe[i][j]);
            }
            if(m > mx){
                mx = m;
                ansr = i;
            }
            //cout<<i<<":"<<m<<endl;
        }
        printf("%d %d\n", ansr+1, mx);
    }

    return 0;
}
