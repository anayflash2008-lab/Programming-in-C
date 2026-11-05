#include<stdio.h>
int main(void)
{
int num,temp,i,j,d,count=0;
printf("Enter a number?");
scanf("%d",&num);
for(i=0;i<=9;i++)
{
temp=num;
while(temp>0)
{
d=temp%10;
if(d==i)
 count++;
temp/=10;
}
if(count!=0)
 printf("%d occurs %d times\n",i,count);
count=0;
}
return 0;
}
