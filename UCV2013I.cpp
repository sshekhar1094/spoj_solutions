#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

/*template <class T>
inline void ri(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-');
		      c=getchar());
	if(c=='-')
		      {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar())
		      i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}*/


int main(){
    double pi = acos(-1),r,n,deg,ans;
    //cout<<acos(-1);
    while(true){
        scanf("%lf%lf", &r, &n);
        if(r==0 && n==0)
            break;
        deg = pi/(2*n);
        //cout<<deg<<endl;
        //cout<<sin(deg);
        ans = r / sin(deg);
        //cout<<ans<<endl;
        printf("%.2f\n", ans);
    }
    return 0;
}
