#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main ()
{
      int t,n,j,i,temp;
      vector<int> v;
      long long r,sum,s;
      cin>>t;

      for(j=0;j<t;j++){
        v.clear();
        temp=0;
        sum=0;
        s=0;
        cin>>r>>n;
        v.resize(n);
        for(i=0; i<n; i++){
            cin>>v[i];
            sum += v[i];
        }
        sort(v.begin(), v.end(), greater<int>());
        if(sum < r)
            cout<<"Scenario #"<<j+1<<":\nimpossible\n";
        else{
            for(i=0; i<n; i++){
                s += v[i];
                temp++;
                if(s >= r){
                    break;
                }
            }
            cout<<"Scenario #"<<j+1<<":\n"<<temp<<endl;;
        }

      }
      return 0;
}


