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
int ct=0;
char s[30];

//Let's get started

void recurse(int pos, int prev, int curr){
    curr = curr + s[pos] - 48;
    if(s[pos+1] == NULL){
        if(curr >= prev)
            ct++;
        return;
    }
    if(curr >= prev){
            recurse(pos+1, curr, 0);

    }
    recurse(pos+1, prev, curr);
}

int main(int argc, char *argv[]){
    int t=1;
    while(1){
        cin>>s;
        if(s[0] == 'b') break;
        ct = 0;
        recurse(0, 0, 0);
        printf("%d. %d\n", t, ct);
        t++;
    }

    return 0;
}
