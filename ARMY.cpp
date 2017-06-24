#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    int ng,mg;
    cin>>t;
    while(t--){
        cin>>ng>>mg;
        vector<int> vg(ng);
        vector<int> vmg(mg);
        for(int i=0; i<ng; i++)
            cin>>vg[i];
        for(int i=0; i<mg; i++)
            cin>>vmg[i];
        sort(vg.rbegin(), vg.rend());
        sort(vmg.rbegin(), vmg.rend());
        while(!vg.empty() && !vmg.empty()){
            if(vg.back() < vmg.back())
                vg.pop_back();
            else
                vmg.pop_back();
        }
        if(vg.empty())
            cout<<"MechaGodzilla\n";
        else
            cout<<"Godzilla\n";
    }

    return 0;
}
