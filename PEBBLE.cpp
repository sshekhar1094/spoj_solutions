#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;

int main(){
    string s;
    int t=0;
    while(cin>>s){
        bool flip = false;
        t++;
        int ct=0;
        for(int i=0; i<s.size(); i++){
            if(flip){
                if(s[i]=='0') s[i]='1';
                else s[i]='0';
            }
            if(s[i] == '1'){
                flip = !flip;
                s[i]='0';
                ct++;
            }
        }
        printf("Game #%d: %d\n", t, ct);
    }

    return 0;
}
