#include<stdio.h>
int main(void)
{
int n=1,num,flag=1,ispersq=0;
scanf("%d",&num);
while(flag)
{
if(n*n==num)
{
 ispersq=1;
 break;
}
if(n*n>num)
{
 flag=0;
}
else
 n++;
}
if(ispersq==1)
 printf("Perfect Square\n");
else
 printf("Not a Perfect Square\n");
return 0;
}

