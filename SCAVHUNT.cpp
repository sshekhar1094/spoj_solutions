#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int fnd(string key, string v[], int sz){
    for(int i=0; i<sz; i++){
        if(v[i] == key)
            return i;
    }
    return -1;
}

int main(){
    int t,n,i,j,k;
    cin>>t;
    string temp;
    for(j=0; j<t; j++){
        cin>>n;
        int flag=0;

        string v1[n-1],v2[n-1];
        for(i=0; i<n-1; i++){
            cin>>v1[i]>>v2[i];
        }
        for(i=0; i<n-1; i++){
            if( fnd(v1[i], v2, n-1) == -1){
                k=i;
                break;
            }
        }
        cout<<"Scenario #"<<j+1<<":"<<endl;
        cout<<v1[k]<<endl;
        for(i=0; i<n-1; i++){
            cout<<v2[k]<<endl;
            k = fnd(v2[k], v1, n-1);
        }
    }
    return 0;
}
