#include<stdio.h>
int main(void)
{
int num=0,n=0,sum=0,flag=0;
float avg;
do
{
scanf("%d",&num);
if(num<0)
 break;
sum+=num;
n++;
flag=1;
}while(1);
if(flag!=0)
{
avg=(float)sum/n;
printf("Sum = %d and Avg = %f\n",sum,avg);
}
else
printf("Your first entry was a negative number and thus AVG is not defined.\n");
return 0;
}


