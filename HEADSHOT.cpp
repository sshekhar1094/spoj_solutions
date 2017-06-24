#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAX 101

using namespace std;

int main(void){

    char no[MAX];
    int i,len,zf,znf,z;

    while(scanf("%s",no)!=EOF){

        len=strlen(no);
        z=0;
        zf=0;
        znf=0;

        for(i=0;i<len;i++){

            if(no[i]=='0'){

                 z++;
                 if(i!=len-1&&no[i+1]=='1')
                     zf++;

                 if(i!=len-1&&no[i+1]=='0')
                    znf++;

            }

        }

        if(no[0]=='1'&&no[len-1]=='0')
                      zf++;

        if(no[0]=='0'&&no[len-1]=='0')
                       znf++;

        if((zf==znf||z==len))
           printf("EQUAL\n");

        else if(znf>zf)
           printf("SHOOT\n");

        else if((znf<zf)&&z!=len)
           printf("ROTATE\n");



    }

    return 0;

}
