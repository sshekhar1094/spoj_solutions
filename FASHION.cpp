#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    vector<int> m(5);
    vector<int> w(5);
    while(t--){
        cin>>n;
        int sum=0;
        w.resize(n);
        m.resize(n);
        for(int i=0; i<n; i++)
            cin>>m[i];
        for(int i=0; i<n; i++)
            cin>>w[i];
        sort(w.rbegin(), w.rend());
        sort(m.rbegin(), m.rend());
        for(int i=0; i<n; i++){
            sum += w[i] * m[i];
        }
        cout<<sum<<endl;
    }

    return 0;
}
