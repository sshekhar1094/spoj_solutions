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
    int t,n,k;
    rd(t);
    while(t--){
        rd(n);
        int arr[n];
        rd(k);
        for(int i=0; i<n; i++) rd(arr[i]);
        for(int i=0; i<k; i++){
            sort(arr, arr+n);
            arr[0] = -1 * arr[0];
            
        }
        int sum = 0;
        for(int i=0; i<n; i++) sum = sum + arr[i];
        printf("%d\n", sum);
    }

    return 0;
}
