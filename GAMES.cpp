#include<stdio.h>
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        gcd(b,a%b);
}
int main()
{
 int t,num,ct,i,j,len,p,flag;
 char s[60];
 scanf("%d",&t);
 while(t--)
 {
  scanf("%s",s);
  len=strlen(s);
  ct=0,flag=1;
  for(j=len-1;j>=0;j--)
  {
   if(s[j]=='.'){
    flag=0;
    break;
   }
   else
    ct++;
  }
  num=0;
  for(j=0;j<len;j++)
  {
   if(s[j]!='.')
   num=10*num+(s[j]-'0');
  }
  p=1;
  if(flag==0){
  for(i=0;i<ct;i++)
  {
   p=p*10;
  }
  }
  printf("%d\n",p/gcd(num,p));
 }
 return 0;
}

