#include<stdio.h>
int main(void)
{
int isprime(int,int);
int n,d;
scanf("%d",&n);
d=isprime(n,2);
if(d==1)
 printf("Prime\n");
else
 printf("Composite\n");
return 0;
}
int isprime(int num,int div)
{
printf("%d %d\n",num,div);
if(num<=1)
 return 0;
if(div*2>num)
 return 1;
if(num%div==0)
 return 0;
else
 return isprime(num,div+1);
}

