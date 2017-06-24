#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int t,n,m,d;
    cin>>t;
    while(t--){
        int flag=0;
        scanf("%d%d%d",&n,&m,&d);
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(a[i]%d==0)
                m = m - a[i]/d + 1;
            else
                m = m - a[i]/d;
        }
        if(m<=0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}
