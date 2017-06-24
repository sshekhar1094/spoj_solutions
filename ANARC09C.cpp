#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    int a,b,o,d,i=0,j,temp,n;
    vector<int> v1,v2,v3;
    for(int j=1; ; j++){
        scanf("%d%d",&a, &b);
        o=0; d=0; temp=0;

        if(a==0 && b==0)
            break;
        printf("%d. ",j);

        n=a;
        while (n%2 == 0){
            v1.push_back(2);
            n = n/2;
        }
        for (int i = 3; i <= sqrt(n); i = i+2)
        {
            while (n%i == 0){
                v1.push_back(i);
                n = n/i;
            }
        }
        if (n > 2)
            v1.push_back(n);


        n=b;
        while (n%2 == 0){
            v2.push_back(2);
            n = n/2;
        }
        for (int i = 3; i <= sqrt(n); i = i+2)
        {
            while (n%i == 0){
                v2.push_back(i);
                n = n/i;
            }
        }
        if (n > 2)
            v2.push_back(n);



        for(int i=0; i<v1.size(); i++){
            if(v1[i] != temp){
                o++;
                v3.push_back(v1[i]);
                temp = v1[i];
            }
        }

        for(int i=0; i<v2.size(); i++){
            if(v2[i] != temp){
                if(!binary_search(v1.begin(), v1.end(), v2[i])){
                    o++;
                    v3.push_back(v2[i]);
                }
                temp = v2[i];
            }
        }
        for(int i=0; i<v3.size(); i++){
            temp = count(v1.begin(), v1.end(), v3[i]) - count(v2.begin(), v2.end(), v3[i]);
            if(temp < 0)
                temp = temp*(-1);
            d += temp;
        }
        printf("%d:%d\n", o, d);
        v1.clear();
        v2.clear();
        v3.clear();
    }
    return 0;
}

