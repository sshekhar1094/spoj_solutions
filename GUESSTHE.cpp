#include<stdio.h>

long long int gcd(long long int a, long long int b)
{
    if (a<b)
        return gcd(b,a);

    if (b==0)
        return a;

    else
            return gcd (b,a%b);
}

long long int lcm(long long int a,long long int b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    char c;
    long long int ct, k, i ,j;

    while(1)
    {
        ct=0;
        k=1;
        i = 0;
        int t[21];
        scanf("%c",&c);
        while(c!='\n' && c!='*')

        {
            ct++;

            if (c=='Y')
            {
                k= lcm(k,ct);
            }
            else if(c=='N')
            {
                t[i++]  = ct;
            }
            scanf("%c",&c);

        }

        for(j = 0 ; j< i ; j++)
        {
            if(k%t[j]==0)
                {
                    k=-1;
                    break;
                }
        }
        if(c=='*')
            break;
        printf("%lld\n",k);

    }
    return 0;
}
