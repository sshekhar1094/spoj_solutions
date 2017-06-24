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

//Globals
vi v;
vector<ll> sum;

//Let's get started

int main(){
    int n,q,t,a,b;
    long long ans;
    rd(n);
    for(int i=0; i<n; i++){
        rd(t);
        v.push_back(t);
    }
    reverse(v.begin(), v.end());
    sum.push_back(v[0]);
    for(int i=1; i<n; i++)
        sum.push_back(sum.back() + v[i]);
    //for(int i=0; i<sum.size(); i++)
        //cout<<sum[i]<<":";
    rd(q);
    while(q--){
        rd(t);
        if(t==1){
            rd(a); rd(b);
            a = n-a;
            b = n-b;
            swap(a,b);
            if(a == 0) ans = sum[b];
            else
                ans = sum[b] - sum[a-1];
            printf("%lld\n", ans);
        }
        else{
            rd(a);
            n++;
            sum.push_back(sum.back() + a);
            //for(int i=0; i<sum.size(); i++)
                //cout<<i<<":"<<sum[i]<<endl;
        }
    }
    return 0;
}
