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
long long arr[50000009] = {0};

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
    long long a, b;
	long long sum = 0;
	rd(a); rd(b);
	long long i = a;
	if (a%2!=0) {
        sum ++;
        i=a+1;
    }
	if (b%2!=0)
        sum ++;
	//cout<<sum<<endl;
	sum += (b-a)/2;
	//cout<<sum<<endl;
	for (; i <= b; i += 2) {
	    if(i%2 != 0) sum++;
		else sum += i&-i;
		//cout<<sum<<endl;
	}
	if (a%2 != 0 && b%2 != 0) --sum;
	printf("%lld\n",sum);
    return 0;
}
