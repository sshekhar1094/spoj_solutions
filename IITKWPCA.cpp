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
char sentence[10009];
set<string> st;

//Lets get started
int main(int argc, char *argv[]){

    int t;
    string sub;
    rd(t);
    while(t--){
        gets(sentence);
        bool flag = 0;
        for(int i=0; sentence[i] != NULL; i++){
            if(sentence[i] != ' ') break;
            if(sentence[i+1] == NULL){
                printf("0\n");
                flag = 1;
            }
        }
        if(flag == 1) continue;
        st.clear();
        istringstream iss(sentence);
        do{
            iss >> sub;
            st.insert(sub);
        } while (iss);
        iss.clear();
        sub = *(st.begin());
        //cout<<sub<<endl;
        if(sub.size() == 0) printf("0\n");
        else
        printf("%d\n", st.size());
    }

    return 0;
}
