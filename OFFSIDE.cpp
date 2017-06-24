#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int a,d;
    vector<int> va(5);
    vector<int> vd(5);
    while(1){
        cin>>a>>d;
        if(a==0 && d==0)
            break;
        va.resize(a);
        vd.resize(d);
        for(int i=0; i<va.size(); i++)
            cin>>va[i];
        for(int i=0; i<vd.size(); i++)
            cin>>vd[i];
        sort(va.begin(), va.end());
        sort(vd.begin(), vd.end());
        if(va[0] < vd[1])
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }

    return 0;
}
