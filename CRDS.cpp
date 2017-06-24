#include<iostream>
using namespace std;

int main(){
    int t;
    int Mx=1000007;
    long long sum,n;
    cin>>t;
    while(t--){
        cin>>n;
        sum=0;
        sum = ( (2*n)%Mx + ((3*n*(n-1))/2)%Mx ) %Mx;
        cout<<sum<<endl;
    }

    return 0;
}
