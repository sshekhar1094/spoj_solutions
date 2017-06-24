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
typedef pair< int ,int > pii;
#define pb push_back
#define mp make_pair
#define inf 99999999
#define _inf INT_MIN

//Globals

//Lets get started
int main(int argc, char *argv[]){
    int n,b;
    while(1){
        rd(n); rd(b);
        if(n+b == 0) break;
        bool pres[n+1];
        int arr[b+1];
        for(int i=0; i<n+1; i++) pres[i] = 0;
        for(int i=0; i<b; i++) rd(arr[i]);
        for(int i=0; i<b; i++){
            for(int j=i; j<b; j++)
                pres[ abs(arr[i] - arr[j]) ] = 1;
        }
        bool ans = 1;
        for(int i=0; i<n+1; i++)
        if(pres[i] == 0){
            //cout<<i<<endl;
            ans = 0;
            break;
        }
        if(ans == 0) printf("N\n");
        else printf("Y\n");

    }

    return 0;
}
