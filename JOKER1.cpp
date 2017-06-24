#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int Mx = 1000000007,t,n,ct,temp;
    vector<int> v;
    bool flag=false;
    cin>>t;
    while(t--){
        ct=1;
        flag = false;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());

        for(int i=0; i<n; i++){
            if(v[i]-i <= 0){
                flag=true;
                break;
            }
            else
                ct = ( ct * (v[i] - i))%Mx;
        }

        if(flag)
            cout<<"0\n";
        else
            cout<<ct<<endl;
        v.clear();
    }
    cout<<"KILL BATMAN\n";
    return 0;
}
