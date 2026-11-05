#include<stdio.h>
int main(void)
{
int num,flag=1,start=1,isps=0;
printf("Input a number you want to check for perfect square");
scanf("%d",&num);
while(flag)
{
if(start*start==num)
{
flag=0;
isps=1;
}
start++;
if(start*start>num)
 flag=0;
}
if(isps==1)
 printf("Perfect Square\n");
else
 printf("Not a perfect square..\n");
return 0;
}
