#include<stdio.h>
int main(void)
{
int num,temp,sumd=0;
scanf("%d",&num);
temp=num;
while(temp>0)
{
sumd=sumd+(temp%10);
temp=temp/10;
}
printf("Sum of Digits of %d is %d\n",num,sumd);
return 0;
}
