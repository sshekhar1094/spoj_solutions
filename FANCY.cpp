#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
    int t;
    char no[30];
    cin>>t;
    while(t--){
        int ct=1,ans;
        long long p=1;
        scanf("%s",no);
        for(int i=1; no[i]!=NULL; i++){
            if(no[i] == no[i-1]){
                ct++;
            }
            else{
                ans = pow(2,ct-1);
                p *= ans;
                ct=1;
            }
            if(no[i+1] == NULL){
                ans = pow(2,ct-1);
                p *= ans;
            }
        }
        cout<<p<<endl;
    }
}
