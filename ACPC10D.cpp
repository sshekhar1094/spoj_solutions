#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
using namespace std;
long long tab[100009][3];

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

long long func(int n){
    tab[0][0] = 999999999;
    tab[0][2] += tab[0][1];
    tab[1][0] += tab[0][1];
    tab[1][1] += min(tab[1][0], min(tab[0][1], tab[0][2]));
    tab[1][2] += min(tab[1][1], min(tab[0][1], tab[0][2]));
    for(int i=2; i<n; i++){
        tab[i][0] += min(tab[i-1][0], tab[i-1][1]);
        tab[i][1] += min(min(tab[i][0],tab[i-1][0]), min(tab[i-1][1], tab[i-1][2]));
        tab[i][2] += min(tab[i][1], min(tab[i-1][1], tab[i-1][2]));
    }
    /*for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
            cout<<tab[i][j]<<" ";
        cout<<endl;
    }*/
    return tab[n-1][1];
}

int main(){
    int n;
    long long ans;
    for(int k=1; ; k++){
        rd(n);
        if(n==0) break;
        for(int i=0; i<n; i++){
            rd(tab[i][0]); rd(tab[i][1]); rd(tab[i][2]);
        }
        ans = func(n);
        printf("%d. %lld\n", k, ans);
    }

    return 0;
}


