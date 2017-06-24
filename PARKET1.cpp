#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;

int main(){
    int r,b,l,h,tot;
    scanf("%d%d", &r, &b);

    tot = r+b;
    for(int i=2; i<=sqrt(tot); i++){
        if(tot%i == 0){
            l = i; h = tot/i;
            if(r == 2*l + 2*(h-2))
                break;
        }
    }

    if(l > h)
        printf("%d %d\n", l,h);
    else
        printf("%d %d\n", h, l);
    return 0;
}
