#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

bool isDivisibleBy7(char a[], int n){
    long long s=0,t;
    for(int i=n-1,j=0; i>=0; i=i-3,j++){
        if(i==1) t = (a[1]-48) + 10*(a[0]-48);
        else if(i==0) t = a[0]-48;
        t = (a[i] - 48) + 10*(a[i-1]-48) + 100*(a[i-2]-48);
        if(j%2==0)
            s = s+t;
        else s = s-t;
    }
    if(s%7==0) return true;
    else return false;
}

int main(){
    char a[245];
    vector<int> yes,no;
    int j;
    while(scanf("%s",a)!=EOF){
        int ct=0,n,sum=0,last,last2, last3,l2,l3;
        for(j=0; a[j]!=NULL; j++){
            n = a[j] - 48;
            sum = sum + n;
            if(a[j+1]==NULL){
                last = n;
                last2 = a[j-1] - 48;
                last3 = a[j-2] - 48;
            }
        }
        l2 = last2*10 + last;
        l3 = last3*100 + l2;
        for(int i=0; a[i]!=NULL; i++){
            n = a[i] - 48;
            no.push_back(0);
            if(binary_search(yes.begin(), yes.end(), n)) ct++;
            else if(binary_search(no.begin(), no.end(),n)) continue;

            else if(n==1){ ct++; yes.push_back(1);}
            else if(n==2){
                if(last%2 == 0){ ct++; yes.push_back(2);}
                else no.push_back(2);
            }
            else if(n==3){
                if(sum %3 == 0){
                    ct++;
                    yes.push_back(3);
                }
                else no.push_back(3);
            }
            else if(n==4){
                if(l2%4 == 0){
                    ct++;
                    yes.push_back(4);
                }
                else no.push_back(4);
            }
            else if(n==5){
                if(last == 5 || last==0) {
                    ct++;
                    yes.push_back(5);
                }
                else no.push_back(5);
            }
            else if(n==6){
                if(last%2==0 && sum%3==0) {
                    ct++;
                    yes.push_back(6);
                }
                else no.push_back(6);
            }
            else if(n==7){
                //copy(a,a+j, b);
                if(isDivisibleBy7(a,j)){
                    ct++;
                    yes.push_back(7);
                }
                else no.push_back(7);
            }
            else if(n==8){
                if(l3%8==0) {
                    ct++;
                    yes.push_back(8);
                }
                else no.push_back(8);
            }
            else if(n==9){
                if(sum%9==0) {
                    ct++;
                    yes.push_back(9);
                }
                else no.push_back(9);
            }

        }
        printf("%d\n", ct);
        yes.clear(); no.clear();
    }

    return 0;
}
