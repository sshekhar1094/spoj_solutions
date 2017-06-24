#include<iostream>
using namespace std;
int main(){
    int t,k;
    char a[40];
    cin>>t;
    for(int j=1; j<=t;j++){
        int TTT=0, TTH=0, THT=0, THH=0, HTT=0, HTH=0, HHT=0, HHH=0;
        cin>>k;
        cin>>a;
        for(int i=0; i<38; i++){
            if(a[i] == 'H'){
                if(a[i+1] == 'T'){
                    if(a[i+2]=='T')
                        HTT++;
                    else
                        HTH++;
                }
                else if(a[i+1] == 'H'){
                    if(a[i+2]=='T')
                        HHT++;
                    else
                        HHH++;
                }
            }
            if(a[i] == 'T'){
                if(a[i+1] == 'T'){
                    if(a[i+2]=='T')
                        TTT++;
                    else
                        TTH++;
                }
                else if(a[i+1] == 'H'){
                    if(a[i+2]=='T')
                        THT++;
                    else
                        THH++;
                }
            }
        }
        cout<<j<<" "<<TTT<<" "<<TTH<<" "<<THT<<" "<<THH<<" "<<HTT<<" "<<HTH<<" "<<HHT<<" "<<HHH<<endl;
    }
    return 0;
}
