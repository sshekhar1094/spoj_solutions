#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t,n,z;
    vector<int> v;
    scanf("%d", &n);
    while(n--){
        z=0;
        scanf("%d", &t);
        if(t%2 != 0)
            printf("%d\n", t);
        else{
            while(t != 1){
                if(t%2==0){
                    v.push_back(0);
                    t /= 2;
                }
                else{
                    v.push_back(1);
                    t = t/2;
                }
            }
            v.push_back(1);
            for(int i=0; i<v.size(); i++){
                if(v[i] == 1)
                    z = z+ pow(2, v.size()-1-i);
            }
            printf("%d\n", z);
        }
        v.clear();
    }
    return 0;
}
