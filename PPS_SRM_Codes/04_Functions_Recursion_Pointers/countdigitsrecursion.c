#include<stdio.h>
int main(void)
{
int count(int);
int n;
scanf("%d",&n);
printf("%d has %d digits\n",n,count(n));
return 0;
}
int count(int num)
{
static int c=0,p;
if(num==0)
 return c;
else
{
c++;
printf("%d %d\n",c,num);
p=count(num/10);
}
}
