#include<stdio.h>
int main(void)
{
int fibo(int);
int n;
scanf("%d",&n);
printf("The %dth Fibonacci Term is %d\n",n,fibo(n));
return 0;
}
int fibo(int f)
{
int d;
if((f==1)||(f==2))
 return 1;
else
d=fibo(f-1)+fibo(f-2);
return d;
}

