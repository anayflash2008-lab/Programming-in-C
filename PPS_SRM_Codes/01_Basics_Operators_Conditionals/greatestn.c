#include<stdio.h>
void main(void)
{
int n,a,greatest;
printf("Enter how many numbers?");
scanf("%d",&n);
printf("Enter a number?");
scanf("%d",&a);
n--;
greatest=a;
k:
printf("Enter a number?");
scanf("%d",&a);
n--;
if(a>greatest)
 greatest=a;
if(n>0)
 goto k;
printf("The greatest number is %d\n",greatest);
}

