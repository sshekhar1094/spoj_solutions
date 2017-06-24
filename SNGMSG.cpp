#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t,temp,sz,j,z;
    cin>>t;
    string key,enc;
    char c;
    while(t--){
        bool ve = true;
        j=0;
        cin>>key>>enc;
        sz = key.size();
        for(int i=0; enc[i]!=NULL; i++){
            temp = key[j] - '0';

            if(ve){
                if(j==sz-1)
                    ve = false;
                else j++;
            }
            else{
                if(j==0) ve = true;
                else j--;
            }

            c = enc[i] - temp;
            z = c;
            if(z<97){
                z = 123 - (97 - z);
                c = z;
                printf("%c", c);
            }
            else
                printf("%c", c);

        }
        cout<<endl;
    }
    return 0;
}
