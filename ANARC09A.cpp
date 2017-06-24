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
char s[2009];

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
    int t,k=0,n,ct;
    vector<char> v;
    while(1){
        scanf("%s", s);
        ct = 0;
        if(s[0] == '-') break;
        if(s[0] == '}')
            ct++;
        v.push_back('{');
        for(int i=1; s[i]!=NULL; i++){
            if(s[i] == '{')
                v.push_back('{');
            else{
                if(v.empty()){
                    ct++;
                    v.push_back('{');
                }
                else v.pop_back();
            }
        }
        n = v.size();
        k++;
        printf("%d. %d\n", k, n/2 + ct);
        v.clear();
    }
    return 0;
}
