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
    int n,a,nxt;
    vector<int> st,v;
    while(true){
        rd(n);
        if(n == 0) break;
        nxt=1;
        for(int i=0; i<n; i++){
            rd(a);
            v.push_back(a);
        }
        for(int i=0; i<n; ){
            //cout<<v[i]<<endl;
            if(v[i] == nxt){
                nxt++;
                i++;
            }
            else{
                if(st.size() != 0 && st.back() == nxt){
                    st.pop_back();
                    nxt++;
                    continue;
                }
                else{
                    st.push_back(v[i]);
                    i++;
                }
            }
        }
        while(st.size() != 0 && st.back() == nxt){
            st.pop_back();
            nxt++;
        }
        if(st.size() == 0)
            printf("yes\n");
        else
            printf("no\n");
        v.clear();
        st.clear();
    }
    return 0;
}
