#include<stdio.h>
int main(void)
{
int n,i,greatest,num;
printf("How many numbers?");
scanf("%d",&n);
printf("Enter a number?");
scanf("%d",&greatest);
for(i=0;i<n-1;i++)
{
printf("Enter a number?");
scanf("%d",&num);
if(num>greatest)
 greatest=num;
}
printf("The greatest number is %d\n",greatest);
return 0;
}
