#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
using namespace std;

template <class T>
inline void rd(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-');
		      c=getchar());
	if(c=='-')
		      {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar())
		      i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}

int main(){
    set< pair<int,int> > s;
    pair<int, int> p;
    set< pair<int,int> > :: iterator it;
    bool ans;

    int t,n,r,t1,t2;
    rd(t);
    for(int i=1; i<=t; i++){
        ans = true;
        rd(n); rd(r);
        for(int j=0; j<r; j++){
            rd(t1); rd(t2);
            p = make_pair(t1,t2);
            it = s.find(p);
            if(it != s.end()){
                ans = false;
            }
            else s.insert(p);
        }
        if(ans) printf("Scenario #%d: possible\n", i);
        else printf("Scenario #%d: impossible\n", i);
        s.clear();
    }

    return 0;
}


