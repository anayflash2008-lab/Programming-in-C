#include<stdio.h>
int main(void)
{
int num,sum=0,n=0;
float avg;
do
{
scanf("%d",&num);
if(num<0)
 break;
sum+=num;
n++;
}while(1);
avg=(float)sum/n;
printf("Sum = %d and Avg=%f\n",sum,avg);
return 0;
}

