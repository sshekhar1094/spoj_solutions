#include<iostream>
using namespace std;

int rev(int x){
    int n=0;
    while(x){
        n = n*10;
        n += x%10;
        x = x/10;
    }
    return n;
}

int main()
{
    int t,a,b,sum;
    cin>>t;
    while(t--){
        cin>>a>>b;
        a = rev(a);
        b = rev(b);
        sum = rev(a+b);
        cout<<sum<<endl;
    }

    return 0;

}

