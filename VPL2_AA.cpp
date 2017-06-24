#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
    int tN, p0,p1,t,p;
    scanf("%d", &tN);
    for (int i=0; i<tN; i++)
    {
        scanf("%d %d %d %d", &p0, &p1, &t, &p);
        printf("Scenario #%d: %.2f\n", i+1, (log(float(p))-log(float(p0)))*t/(log(float(p1))-log(float(p0))));
    }
    return 0;
}

