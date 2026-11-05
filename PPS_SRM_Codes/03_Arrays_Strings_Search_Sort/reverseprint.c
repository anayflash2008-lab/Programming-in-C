#include<stdio.h>
int main(void)
{
int num,numt,sum=0;
scanf("%d",&numt);
num=numt;
while(num>0)
{
sum=(sum*10)+(num%10);
num=num/10;
}
numt=sum;
printf("%d\n",numt); //The number is reversed
return 0;
}

