#include <stdio.h>
#include<iostream>
using namespace std;

int josephus(int n, int k)
{
    if (n==1)
        return 1;
    return (josephus(n - 1, k+1) + k-1) % n + 1;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<5)
            cout<<"2\n";
        else{
            cout<<josephus(n,1)<<endl;
        }
    }
    return 0;
}
