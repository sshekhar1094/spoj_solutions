#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;

int main()
{
    int a[1001]; a[0]=0;a[1]=30; a[2]=42;
    int n,k=3;
    for(int i=43; i<2665; i++){
        n=i;int ct=0;
        if(n%2==0) ct++;
        while(n%2==0) n=n/2;
        for(int j=3; j<sqrt(n); j=j+2){
            if(n%j==0){
                ct++;
            }
            while(n%j==0) n=n/j;
            if(ct >= 3){
                a[k] = i;
                k++;
                break;
            }
        }
        if(n>2 && ct==2){
            a[k]=i;
            k++;
        }
    }
    //for(int i=0; i<1000; i++)
        //cout<<i<<":"<<a[i]<<"\t";
    int t;
    scanf("%d",&t);
    int no;
    while(t--){
        scanf("%d", &no);
        printf("%d\n", a[no]);
    }

    return 0;
}
