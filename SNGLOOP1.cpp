#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
int main()
{
    int t,n,m,p;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        p = (m-n)%4;

        switch(p){
            case 0: printf("1\n");
                    break;
            case 1: printf("3\n");
                    break;
            case 2: printf("9\n");
                    break;
            case 3: printf("7\n");
                    break;
        }

    }

    return 0;
}
