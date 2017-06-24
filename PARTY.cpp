#include <algorithm>
#include <iostream>
#include<vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include<stdio.h>
using namespace std;

int main()
{
    int c,ans;
    int V[101],W[101],n,sum;
    while(true){
        scanf("%d%d", &c, &n);
        if(c==0 && n==0) break;
        for(int i=0; i<n; i++)
            scanf("%d%d",&W[i], &V[i]);

        int i, w;
        int K[n+1][c+1];
        for (i = 0; i <= n; i++){
           for (w = 0; w <= c; w++){
               if (i==0 || w==0)
                   K[i][w] = 0;
               else if (W[i-1] <= w)
                     K[i][w] = max(V[i-1] + K[i-1][w-W[i-1]],  K[i-1][w]);
               else
                     K[i][w] = K[i-1][w];
           }
        }
        ans = K[n][c];
        for(i=c;i;i--) if(K[n][i]<ans) break;

        printf("%d %d\n", i+1, ans);
    }
	return 0;
}
