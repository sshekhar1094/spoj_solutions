#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>

using namespace std;
int main()
{
    int d,n;
    vector<int> v;
    while(true){
        int flag=0;
        //scanf("%d", &n);
        cin>>n;
        if(n==0) break;
        for(int i=0; i<n; i++){
            //scanf("%d", &d);
            cin>>d;
            v.push_back(d);
        }
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++){
            if(i!=0){
                if( (v[i] - v[i-1]) > 200){
                    flag=1; break;
                }
                if(i==n-1){
                    if((1422 - v[i])*2 > 200){
                        flag=1; break;
                    }
                }
            }
        }
        if(flag==1)
            cout<<"IMPOSSIBLE"<<endl;
            //printf("IMPOSSIBLE\n");
        else
            cout<<"POSSIBLE"<<endl;
            //printf("POSSIBLE\n");
        v.clear();
    }
    return 0;
}
