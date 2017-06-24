#include<iostream>
using namespace std;

int main()
{
    long long t,n,sum;
    cin>>t;
    while(t--){
        sum=0;
        cin>>n;
        long long a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
            sum += (a[i] % n);
            if(sum%n == 0)
                sum = 0;
        }
        if(sum == 0)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
    return 0;
}

