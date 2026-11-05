//REcursive Formula:
//power(n,m)=n*power(n,m-1) when m>1
//power(n,1)=n when m=1
#include<stdio.h>
int main(void)
{
int power(int,int );
int a,b;
scanf("%d",&a);
scanf("%d",&b);
printf("%d\n",power(a,b));
return 0;
}
int power(int x,int y)
{
if(y==1)
 return x;
else
 return x*power(x,y-1);
}
