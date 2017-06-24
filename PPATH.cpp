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
bool prime[10009] = {0};

void sieve(){
    for(int i=1000; i<10009; i++) prime[i] = 0;
    for(int i=2; i*i<10009 ; i++){
        if(prime[i] == 0){
            for(int j=2; i*j<10009; j++)
                prime[i*j] = 1;
        }
    }
}

void toArr(int arr[], int t){
    int i=3;
    while(t){
        arr[i] = t % 10;
        t = t/10;
        i--;
    }
}

int toNo(int arr[]){
    int no=0;
    for(int i=0; i<4; i++){
        no = no * 10;
        no = no + arr[i];
    }
    return no;
}

int main(int argc, char *argv[]){
    sieve();
    int t,a,b,u,v;
    int digit[5], level[10009];
    queue<int> Q;
    rd(t);
    while(t--){
        for(int i=1000; i<10009; i++) level[i] = -1;
        rd(a); rd(b);
        level[a] = 0;
        Q.push(a);
        while(!Q.empty()){
            u = Q.front();
            Q.pop();
            for(int i=0; i<4; i++){
                toArr(digit, u);
                for(int j=0; j<10; j++){
                    digit[i] = j;
                    v = toNo(digit);
                    //cout<<v<<":"<<prime[v]<<":"<<level[v]<<endl;
                    if(!prime[v] && level[v] == -1 && v>999){
                        Q.push(v);
                        level[v] = level[u] + 1;
                        //cout<<"\t"<<v<<":"<<level[v]<<endl;
                        if(v == b) break;
                    }
                }
                if(v == b) break;
            }
            if(v == b) break;
        }
        while(!Q.empty()) Q.pop();
        if(level[b] == -1) printf("Impossible\n");
        else printf("%d\n", level[b]);
    }

    return 0;
}
