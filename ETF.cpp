#include<iostream>
#include<stdio.h>
using namespace std;

int fi(int n)
     {
       int result = n;
       for(int i=2;i*i <= n;i++)
       {
         if (n % i == 0) result -= result / i;
         while (n % i == 0) n /= i;
       }
       if (n > 1) result -= result / n;
       return result;
     }

int main(){
    int ct,t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<fi(n)<<endl;
    }
    return 0;
}
