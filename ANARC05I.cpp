#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
int arr[2014][2014];

int main(void){
    int i,ct,X,Y;
    char str[1000];

    while(1){
        scanf("%s",str);
        if(str[0]=='Q')
           break;

        ct=0;
        X=Y=1001;
        i=0;
        memset(arr,0,sizeof(int)*2014*2014);
        arr[X][Y]=1;
        while(str[i]!='Q'){
            switch(str[i]){
                case 'U':
                    X--;
                    if(arr[X][Y]==1)
                        ct++;

                    else arr[X][Y]=1;
                    break;

                case 'D' :
                    X++;
                    if(arr[X][Y]==1)
                        ct++;

                    else arr[X][Y]=1;
                    break;

                case 'L' :
                    Y--;
                    if(arr[X][Y]==1)
                        ct++;

                    else arr[X][Y]=1;
                    break;

                case 'R' :
                    Y++;
                    if(arr[X][Y]==1)
                        ct++;

                    else arr[X][Y]=1;
                    break;

            }
            i++;

        }

        printf("%d\n",ct);

    }

    return 0;

}
