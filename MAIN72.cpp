#include<iostream>
#include<stdio.h>
#include<string>
#include<iosfwd>
using namespace std;
bool subsum[101][100001];
/*
template <class T>
inline void ri(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-');
		      c=getchar());
	if(c=='-')
		      {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar())
		      i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}*/

long long func(int a[], int n, int arsum){
    long long sum=0;
    for(int i=1; i<=n; i++){
        for(long long j=1; j<= arsum; j++){
            if(j < a[i-1])
                subsum[i][j] = subsum[i-1][j];
            else
                subsum[i][j] = subsum[i-1][j-a[i-1]] || subsum[i-1][j];
            //if(subsum[i][j]) sum = sum + j;
        }
    }
    for(long long j=1; j<=arsum; j++)
        if(subsum[n][j]) sum = sum + j;
    return sum;
}

int main(){
    int t,n;
    //ri(t);
    scanf("%d", &t);
    long long sum, arsum;
    while(t--){
        //memset(arr,0,sizeof(int)*10100101);
        //ri(n);
        scanf("%d", &n);
        arsum=0;
        int a[n];
        for(int i=0; i<n; i++){
            //ri(a[i]);
            scanf("%d", &a[i]);
            arsum = arsum + a[i];
        }
        for(int i=0; i<=n; i++) subsum[i][0] = true;
        sum = func(a,n,arsum);
        printf("%lld\n", sum);

    }
}

