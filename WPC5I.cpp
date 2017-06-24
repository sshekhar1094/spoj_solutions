#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    int t, a,b,temp,n,tp1,tp2;
    unsigned long long k;
    vector<int> v1,v2,v3;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        v1.clear(); v2.clear(); k=1; temp=0; v3.clear();
        if(a==b){
            printf("1\n");
            continue;
        }

        n = a;
        while (n%2 == 0){
            v1.push_back(2);
            n = n/2;
        }
        for (int i = 3; i <= sqrt(n); i = i+2){
            while (n%i == 0){
                v1.push_back(i);
                n = n/i;
            }
        }
        if (n > 2)
            v1.push_back(n);

        n = b;
        while (n%2 == 0){
            v2.push_back(2);
            n = n/2;
        }
        for (int i = 3; i <= sqrt(n); i = i+2){
            while (n%i == 0){
                v2.push_back(i);
                n = n/i;
            }
        }
        if (n > 2)
            v2.push_back(n);

        for(int i=0; i<v1.size(); i++){
            if(v1[i] != temp){
                v3.push_back(v1[i]);
                temp = v1[i];
            }
        }
        for(int i=0; i<v2.size(); i++){
            if(v2[i] != temp){
                if(!binary_search(v1.begin(), v1.end(), v2[i])){
                    v3.push_back(v2[i]);
                }
                temp = v2[i];
            }
        }


        for(int i=0; i<v3.size(); i++){
            tp1 = count(v1.begin(), v1.end(), v3[i]);
            tp2 = count(v2.begin(), v2.end(), v3[i]);
            if(tp1 > tp2 )
                temp = tp1;
            else if(tp1 < tp2) temp = tp2;
            else temp = 0;
            //k *= pow(v3[i], temp);
            while(temp--){
                 k *= v3[i];
            }
        }
        printf("%lld\n", k);

    }
    return 0;
}

