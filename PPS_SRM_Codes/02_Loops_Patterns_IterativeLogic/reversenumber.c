#include<stdio.h>
void main(void)
{
int n,r,m,t=0;
printf("Enter a number?");
scanf("%d",&m);
n=m;
while(n!=0)
{
r=n%10;
t=(t*10)+r;
n=n/10;
}
printf("The reverse of %d is %d\n",m,t);
}


