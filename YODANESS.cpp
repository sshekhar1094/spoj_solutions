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
map<string, int> m;
long long ct;

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
        if(lf[i] <= rf[j]){
            a[k] = lf[i];
            i++; k++;
        }
        else{
            a[k] = rf[j];
            j++;
            k++;
            ct = ct + nl - i;
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
    char tmp[25];
    int a[30009];
    while(t--){
        rd(n);
        ct = 0;
        string s[n+10];
        int i=1;
        for(i=0; i<n; i++){
            cin>>s[i];
            m[s[i]] = i;
        }
        for(i=0; i<n; i++){
            cin>>tmp;
            a[i] = m[tmp];
        }
        mergeSort(a,n);
        //for(i=0; i<n; i++) cout<<arr[i]<<" ";
        printf("%lld\n", ct);
        m.clear();
    }
    return 0;
}
