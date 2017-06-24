#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> a , pair<int,int> b)
{
    return (a.first < b.first);
}

int main()
{
    int tst;
    cin>>tst;
    while(tst--)
    {
        vector<pair<int,bool> > t;
        vector<pair<int,bool> >::iterator i;
        pair<int , bool > p;
        int ans=0;
        int n=0;
        int ct=0;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int a,b;
            cin>>a>>b;
            p.first=a;
            p.second=true;
            t.push_back(p);
            p.first=b;
            p.second=false;
            t.push_back(p);
        }
        sort(t.begin(),t.end(),compare);
        for(i=t.begin(); i!=t.end(); i++)
        {
            if((*i).second==true)
                ct++;
            else
                ct--;
            ans=max(ct,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}

