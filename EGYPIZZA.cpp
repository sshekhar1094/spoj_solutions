#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n,ct1=0,ct2=0,ct3=0, ans=0;
    cin>>n;
    char a[n][3];
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i][0]=='1' && a[i][2]=='4')
            ct1++;
        else if(a[i][0]=='1' && a[i][2]=='2')
            ct2++;
        else
            ct3++;
    }
    if(ct2%2!=0 && ct1>1)
        ct1 = ct1-2;
    if(ct1>ct3)
        ct1 = ct1-ct3;
    else
        ct1=0;
    ct1 = ceil(0.25*ct1);
    ct2 = ceil(0.5*ct2);
    ans = 1+ct1+ct2+ct3;
    cout<<ans<<endl;
    return 0;
}
