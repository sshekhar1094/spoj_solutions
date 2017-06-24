#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <set>
using namespace std;

template <class T>
inline void rd(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-'); c=getchar());
	if(c=='-') {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar()) i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}

int main(){
    vector<long long> v;
    long long n,k,t;
    rd(n); rd(k);
    for(long long i=0; i<n; i++){
        rd(t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    long long ct = 0;
    for(long long i=0; i<n; i++)
        if(binary_search(v.begin(), v.end(), v[i] + k)) ct++;
    printf("%lld\n", ct);
    return 0;
}
