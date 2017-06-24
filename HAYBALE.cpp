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

int main()
{
     int N,U;
          scanf("%d%d",&N,&U);
          //cout<<N<<U<<endl;
          int A[N],T[N+1],low,high,i,count=0,val=1;
          for(i=0;i<=N;i++)
                T[i]=0;
          for(i=0;i<U;i++){
               scanf("%d%d",&low,&high);
               T[low]+=val;
               T[high+1]-=val;
          }
          //cout<<"here\n";
          for(i=0;i<N;i++){
               count+=T[i];
               A[i]=count;
          }
          sort(A, A+N);
        printf("%d\n", A[(N)/2]);
     return 0;
}
