#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
char a[50000];

bool isDivisibleBy7(char a[], int n){
    long long s=0,t;
    for(int i=n-1,j=0; i>=0; i=i-3,j++){
        //cout<<(a[0]-48)*10 + a[1]-48<<endl;
        if(i==1) t = (a[0]-48)*10 + a[1]-48;
        else if(i==0) t = a[0]-48;
        else t = (a[i] - 48) + 10*(a[i-1]-48) + 100*(a[i-2]-48);
        if(j%2==0)
            s = s+t;
        else s = s-t;
        //cout<<"i="<<i<<" t="<<t<<endl;
    }

    if(s%7==0) return true;
    else return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s", a);
        int sum=0, last,last2,l2,j,n;
        bool b1=false, b2=false;
        int tmp=99;
        for(j=0; a[j]!=NULL; j++){
            n = a[j] - 48;
            sum = sum + n;
            if(a[j+1]==NULL){
                last = n;
                last2 = a[j-1] - 48;
            }
        }
        l2 = last2*10 + last;

        //For 252
        if(l2 % 4==0) {b1=true; }
        if(b1){
            if(sum % 9 != 0) {b1 = false;}
            if(b1){
                if(isDivisibleBy7(a,j)){
                    //b1=true;
                    tmp=1;
                }
                else{
                    b1=false;
                    tmp=0;
                    //cout<<"not by 7"<<endl;
                }
            }
        }

        //For 525
        if(l2==0 || l2==25 || l2==50 ||l2==75) b2=true;
        if(b2){
            if(sum%3 != 0) b2=false;
            if(b2){
                if(tmp==1) b2=true;
                else if(tmp==0) b2 = false;
                else if(isDivisibleBy7(a,j)) b2=true;
                else b2=false;
            }
        }
        if(b1) printf("Yes ");
        else printf("No ");
        if(b2) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
