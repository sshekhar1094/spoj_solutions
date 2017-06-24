#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> R,r;
    int t,m,n,a,b,d,mr,in,mR;
    scanf("%d", &t);
    while(t--){
        mr =0;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d%d", &a, &b);
            r.push_back(a);
            R.push_back(b);
            if(a > mr){
                mr = a;
                in = i;
            }
        }
        R.erase(R.begin()+in);
        mR = *max_element(R.begin(), R.end());
        if(mR < mr)
            printf("%d\n", in+1);
        else printf("-1\n");
        R.clear();
        r.clear();
    }
    return 0;
}
