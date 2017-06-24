#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
using namespace std;

double mnDiff(double a[], int n){
    double mn, d;
    sort(a, a+n);
    mn = a[n-1] - a[0];
    for(int i=1; i<n; i++){
        d = 360 - a[i] + a[i-1];
        if(d < mn) mn =d;
    }
    return mn;
}

int main()
{
    double tot = 4320.0,dif,time,deg=360.0;
    int t,r,n;
    char s[50];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        double a[n];
        for(int i=0; i<n; i++){
            scanf("%s", &s);
            scanf("%lf", &a[i]);
            //cout<<s<<" "<<a[i]<<endl;
        }
        dif = mnDiff(a,n);
        time = (dif/deg) * tot;
        r = ceil(time);
        printf("%d\n", r);
    }
	return 0;
}
