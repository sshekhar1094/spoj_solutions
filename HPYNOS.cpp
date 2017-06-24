#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int get(int n){
    int r,s=0;
    while(n){
        r= n%10;
        s += r*r;
        n=n/10;
    }
    return s;
}

int main(){
    int n,ct=0;
    vector<int> v;
        cin>>n;
        while(n){
            n = get(n);
            ct++;
            if(n==1 || binary_search(v.begin(), v.end(), n) || n==19)
                break;
            v.push_back(n);

        }
        if(n==1)
            cout<<ct<<endl;
        else if(n==19)
            cout<<ct+4<<endl;
        else
            cout<<"-1\n";

    return 0;
}
