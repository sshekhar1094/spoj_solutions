#include<iostream>
#include<stdio.h>
#include<string>
#include<iosfwd>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
long long arr[1000000];
char s[1000000];

int main(){
    int no,i;
    long long ans;
    while(true){
        scanf("%s", s);
        if(s[0] == '0') break;
        arr[0]=1;
        no = ( s[0] - '0' )*10 + s[1]-'0';
        if(no <= 26) {if(s[1]!=NULL)arr[1] = 2;}
        else if(s[1]!=NULL) arr[1] = 1;
        if(no%10 == 0) if(s[1]!=NULL) arr[1]=1;
        if(no %10 == 0 && no>26){
            printf("0\n"); continue;
        }
        if(s[1]!=NULL) ans=arr[1]; else ans =arr[0];
        if(s[1]!=NULL)
        for(i=2; s[i]!=NULL; i++){
            no = ( s[i-1] - '0' )*10 + s[i]-'0';
            //cout<<no<<endl;
            if(no <= 26 && no>9) arr[i] = arr[i-1] + arr[i-2];
            else arr[i] = arr[i-1];
            if(no%10==0){
                if(no > 26){ans = 0; break;}
                arr[i] = arr[i-2];
            }
            ans = arr[i];
        }
        printf("%lld\n", ans);

    }
    return 0;
}



