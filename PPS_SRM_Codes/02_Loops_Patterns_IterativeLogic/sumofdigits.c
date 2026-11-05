#include<stdio.h>
void main(void)
{
int n,sum=0,r,m;
printf("Enter a number?");
scanf("%d",&m);
n=m;
printf("The reverse of number is:");
while(n!=0)
{
r=n%10;
printf("%d",r);
sum=sum+r;
n=n/10;
}
printf("\nSum of Digits of %d is %d\n",m,sum);
}

