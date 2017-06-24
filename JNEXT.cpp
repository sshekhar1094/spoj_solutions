#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>

using namespace std;
int main()
{
    int t,n;
    scanf("%d", &t);
    while(t--){
        scanf("%d",&n);
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        if(next_permutation(arr, arr+n))
            for(int i=0; i<n; i++)
                printf("%d", arr[i]);
        else
            printf("-1");
        printf("\n");
    }
    return 0;
}
