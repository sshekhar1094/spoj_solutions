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
long long ct;
int a[100009];

template <class T>
inline void rd(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-'); c=getchar());
	if(c=='-') {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar()) i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}

void mrge(int lf[], int rf[], int a[], int nl, int n){
    int nr = n-nl, i=0,j=0,k=0;
    while( i<nl && j<nr){
        if(lf[i] < rf[j]){
            a[k] = lf[i];
            ct = ct + (long long)(a[k]*(nr - j));
            i++; k++;
        }
        else{
            a[k] = rf[j];
            j++;
            k++;
        }
    }
    while(i<nl){
        a[k] = lf[i];
        i++;
        k++;
    }
    while(j<nr){
        a[k] = rf[j];
        k++;
        j++;
    }
}

void mergeSort(int a[], int n){
    if(n<2)
        return;
    int mid = n/2,i;
    int lf[mid], rf[n-mid];
    for(i=0; i<mid; i++)
        lf[i] = a[i];
    for(i=mid; i<n; i++)
        rf[i-mid] = a[i];
    mergeSort(lf, mid);
    mergeSort(rf, n-mid);
    mrge(lf,rf,a,mid,n);
}

int main(){
    int t,n;
    rd(t);
    while(t--){
        rd(n);
        ct = 0;
        for(int i=0; i<n; i++) rd(a[i]);
        mergeSort(a,n);
        printf("%lld\n",ct);
    }
    return 0;
}
