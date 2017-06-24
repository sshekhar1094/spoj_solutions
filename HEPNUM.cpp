#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;

string a1,a2;
int main(){
    while(true){
        cin>>a1>>a2;
        if(a1 == "*")
            break;
        int flag=0;
        int i = a1.size(), j=a2.size();
        if(i>j){
            for(int k=1; k<=j; k++){
                if(a1[i-k] > a2[j-k] ){
                    flag=1;
                }
                else if(a1[i-k] < a2[j-k])
                    flag=2;
            }
            //if(flag==0){
                for(int k=j+1; i-k>=0; k++){
                    if(a1[i-k] != '0'){
                        flag=1; break;
                    }
                }
            //}
            if(flag==0) printf("=\n");
            else if(flag==1) printf(">\n");
            else if(flag==2) printf("<\n");
        }

        else{
            for(int k=1; k<=i; k++){
                if(a1[i-k] > a2[j-k] ){
                    flag=1;
                }
                else if(a1[i-k] < a2[j-k])
                    flag=2;
            }
            //if(flag==0){
                for(int k=i+1;j-k>=0; k++){
                    if(a2[j-k] != '0'){
                        flag=2; break;
                    }
                }
            //}
            if(flag==0) printf("=\n");
            else if(flag==1) printf(">\n");
            else printf("<\n");
        }
    }
    return 0;
}
