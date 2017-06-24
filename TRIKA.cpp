#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iosfwd>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
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
    int n,m,x,y;
    rd(n); rd(m); rd(x); rd(y);
    int arr[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            rd(arr[i][j]);
    x--; y--;
    for(int i=x+1; i<n; i++) arr[i][y] = arr[i-1][y] - arr[i][y];
    for(int i=y+1; i<m; i++) arr[x][i] = arr[x][i-1] - arr[x][i];
    for(int i=x+1; i<n; i++){
        for(int j=y+1; j<n; j++){
            arr[i][j] = max(arr[i-1][j], arr[i][j-1]) - arr[i][j];
        }
    }
    if(arr[n-1][m-1] >= 0) printf("Y %d\n", arr[n-1][m-1]);
    else printf("N\n");
}

