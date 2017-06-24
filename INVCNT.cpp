#include<iostream>
#include<stdio.h>
using namespace std;
long long ct;

void mrge(long long lf[], long long rf[], long long a[], long long nl, long long n){
    long long nr = n-nl, i=0,j=0,k=0;
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

void mergeSort(long long a[], long long n){
    if(n<2)
        return;
    long long mid = n/2,i;
    long long lf[mid], rf[n-mid];
    for(i=0; i<mid; i++)
        lf[i] = a[i];
    for(i=mid; i<n; i++)
        rf[i-mid] = a[i];
    mergeSort(lf, mid);
    mergeSort(rf, n-mid);
    mrge(lf,rf,a,mid,n);
}

int main(){
    long long n;
    int t;
    scanf("%d", &t);
    while(t--){
        ct=0;
        scanf("%lld", &n);
        long long a[n];
        for(long long i=0; i<n; i++)
            scanf("%lld", &a[i]);
        mergeSort(a,n);
        printf("%lld\n", ct);
    }

    /*cout<<"Enter size of array";
    cin>>n;
    long long a[n];
    cout<<"Enter elements:";
    for(long long i=0; i<n; i++)
        cin>>a[i];
    mergeSort(a,n);
    for(long long i=0; i<n; i++)
        cout<<a[i]<<"\t";
    cout<<"\nInversions="<<ct;
    */
    return 0;
}
