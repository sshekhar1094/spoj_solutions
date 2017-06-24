#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iosfwd>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
int arr[300005];

template <class T>
inline void rd(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-');
		      c=getchar());
	if(c=='-')
		      {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar())
		      i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}

/*inline void fastWrite(int Number){

	if(Number==0){	putchar('0'); putchar('\n'); return; }
	int reversedNumber=0,count=0;
	while(Number%10==0){  count++; Number/=10;	}
	while(Number){ reversedNumber=reversedNumber*10+Number%10; Number/=10;}
	while(reversedNumber){	putchar(reversedNumber%10+'0'); reversedNumber/=10;	}
	while(count--) putchar('0');
	putchar('\n');

}*/

void func(int n, int m){
    int a=0,b=0,sum=0, mx=0;
    for(int i=0; i<n; i++){
        sum = sum+arr[b];
        b++;
        while(sum > m){
            sum = sum - arr[a];
            a++;
        }
        if(sum > mx) mx=sum;
        if(mx == m)break;
    }
    printf("%d\n", mx);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
        //rd(arr[i]);
    func(n,m);
	return 0;
}
