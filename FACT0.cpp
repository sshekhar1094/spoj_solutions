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
map<long long, long long> m;

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
    long long n;
    map<long long, long long> :: iterator it;
    while(true){
        rd(n);
        if(n==0) break;

        while(n%2 == 0){
            m[2]++;
            n = n/2;
        }
        for(long long i=3; i<=sqrt(n); i=i+2){
            while(n%i == 0){
                m[i]++;
                n = n/i;
            }
        }
        if(n > 2) m[n]++;

        for(it = m.begin(); it != m.end(); it++){
            printf("%lld^%lld ", it->first, it->second);
        }
        printf("\n");
        m.clear();
    }
    return 0;
}
