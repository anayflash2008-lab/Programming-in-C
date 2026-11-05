#include<stdio.h>
int main(void)
{
int n;
int i=0; 
int sum=0;
printf("Enter a number whose factors you want?");
scanf("%d",&n);
x:
i++;
if(n%i==0)
 printf("%d\n",i);
if(i<=n-1)
 goto x;
return 0;
}

