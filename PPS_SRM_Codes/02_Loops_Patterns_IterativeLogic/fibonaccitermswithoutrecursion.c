#include<stdio.h>
int main(void)
{
int n,f=0,s=1,t;
scanf("%d",&n);
if(n==1)
 printf("%d\n",f);
else if(n==2)
       printf("%d %d\n",f,s);
else
{
printf("%d\n%d\n",f,s);
n-=2;
while(n>0)
{
t=f+s;
printf("%d\n",t);
f=s;
s=t;
n--;
}
}
return 0;
}
