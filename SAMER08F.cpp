#include<iostream>
using namespace std;

int main(){
    long long n;
    while(1){
        cin>>n;
        if(n==0)
            break;
        cout<<(n*(n+1)*(2*n +1))/6<<endl;
    }
    return 0;
}
