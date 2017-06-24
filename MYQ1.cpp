#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;

int main()
{
    int t, md;
    long long n,r;
    char d,s;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        if(n == 1){
            printf("poor conductor\n");
            continue;
        }
        r = (n-2)/5 + 1;
        printf("%lld ", r);
        if(r==1) md=n;
        else
            md = n % (5* (r-1));
        if(r%2==0){
            if(md==2)
                printf("W R\n");
            else if(md==3)
                printf("M R\n");
            else if(md==4)
                printf("A R\n");
            else if(md==5)
                printf("A L\n");
            else if(md==6)
                printf("W L\n");
        }
        else{

            if(md==2)
                printf("W L\n");
            else if(md==3)
                printf("A L\n");
            else if(md==4)
                printf("A R\n");
            else if(md==5)
                printf("M R\n");
            else if(md==6)
                printf("W R\n");
        }
    }

    return 0;
}
