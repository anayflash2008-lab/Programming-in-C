#include<stdio.h>
int main(void)
{
int num,temp,count=0,i,j,d;
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
 printf("There are %d %d's in %d\n",count,i,num);
count=0;
}
return 0;
}

