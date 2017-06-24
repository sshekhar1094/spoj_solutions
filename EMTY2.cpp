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
#define inf INT_MAX
#define _inf INT_MIN

//Globals

//Lets get started
int main(int argc, char *argv[]){
    bool t1,t2,t3;
    string str;
    int t;
    rd(t);
    for(int k=0; k<t; k++){
        cin>>str;
        stack<bool> st;
        for(int i=0; i<str.size(); i++){
            st.push(str[i] - 48);
            if(st.size() >= 3){
                t1 = st.top();
                st.pop();
                t2 = st.top();
                st.pop();
                t3 = st.top();
                st.pop();
                if(t1==0 && t2==0 && t3==1){}
                else{
                    st.push(t3);
                    st.push(t2);
                    st.push(t1);
                }
            }
        }
        if(st.size()==0) printf("Case %d: yes\n", k+1);
        else printf("Case %d: no\n", k+1);
    }
    return 0;
}
