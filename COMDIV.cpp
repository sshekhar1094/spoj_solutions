#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>

long long gcd(long long a, long long b){
    long long t;
    while (b != 0){
       t = b;
       b = a % b;
       a = t;
    }
    return a;
}

using namespace std;
int main()
{
    long long t, a,b,hcf,n;
    vector<int> v;
    scanf("%lld", &t);
    while(t--){
        v.clear();
        long long ans=1, ct=0, temp=0;
        scanf("%lld%lld", &a, &b);
        hcf = gcd(a,b);
        n = hcf;
        // Print the number of 2s that divide n
        while (n%2 == 0)
        {
            v.push_back(2);
            n = n/2;
            ct++;
        }
        ans = ct+1;
        ct=0;
        // n must be odd at this point.  So we can skip one element (Note i = i +2)
        for (long long i = 3; i <= sqrt(n); i = i+2)
        {
            while (n%i == 0)
            {
                ct++;
                v.push_back(i);
                n = n/i;
                temp = i;
            }
            ans = ans * (ct+1);
            ct=0;
        }

        if (n > 2){
            v.push_back(n);
            ans = ans*2;
        }
        printf("%lld\n", ans);
    }
    v.clear();
    return 0;
}
