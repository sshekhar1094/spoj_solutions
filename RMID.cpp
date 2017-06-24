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
priority_queue<int, vector<int> > mxhp;
priority_queue<int, vector<int>, greater<int> > mnhp;

//Lets get started
void empty(){
    while(!mxhp.empty()) mxhp.pop();
    while(!mnhp.empty()) mnhp.pop();
}

void rebalance(){
    int n1 = mxhp.size(), n2=mnhp.size(), a;
    if(n1 == n2) return;
    if(n1+n2 % 2 == 0 ){
        if(n1 > n2+1){
            a = mxhp.top();
            mxhp.pop();
            mnhp.push(a);
        }
        else{
            a = mnhp.top();
            mnhp.pop();
            mxhp.push(a);
        }
    }
    else{
        if(n2 > n1){
            a = mnhp.top();
            mnhp.pop();
            mxhp.push(a);
        }
    }
}

int main(int argc, char *argv[]){
    int n1=0, n2=0;
    int a, b;
    while(scanf("%d", &a) == 1){
        empty();
        rd(b);
        if(b==0){
            printf("\n");
            continue;
        }
        else if(b == -1) printf("%d\n", a);
        else{
            mxhp.push(min(a,b));
            mnhp.push(max(a,b));
        }
        while(1){
            rd(a);
            if(a == 0){
                printf("\n");
                break;
            }
            if(a == -1){
                printf("%d\n", mxhp.top());
                mxhp.pop();
                rebalance();
            }
            else{
                if(a >= mnhp.top()) mnhp.push(a);
                else mxhp.push(a);
                rebalance();
                //cout<<mxhp.size()<<":"<<mnhp.size()<<endl;
            }
        }
    }

    return 0;
}
