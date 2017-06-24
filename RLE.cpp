#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    char c, temp=' ';
    int ct=0;
    while(scanf("%c",&c) != EOF){
        if(c == '\n'){
            if(ct==1)
                cout<<temp;
            else if(ct==2)
                cout<<temp<<temp;
            else if(ct==3)
                cout<<temp<<temp<<temp;
            else
                cout<<ct<<"!"<<temp;
            ct=0;
            temp = ' ';
            cout<<endl;
        }
        else{
            if(ct==0){
                temp = c;
                ct++;
            }
            else{
                if(c==temp){
                    ct++;
                }
                else{
                    if(ct==1)
                        cout<<temp;
                    else if(ct==2)
                        cout<<temp<<temp;
                    else if(ct==3)
                        cout<<temp<<temp<<temp;
                    else
                        cout<<ct<<"!"<<temp;
                    ct=1;
                    temp = c;
                }
            }

        }
    }
    if(ct==1)
        cout<<temp;
    else if(ct==2)
        cout<<temp<<temp;
    else if(ct==3)
        cout<<temp<<temp<<temp;
    else
        cout<<ct<<"!"<<temp;
    return 0;
}

