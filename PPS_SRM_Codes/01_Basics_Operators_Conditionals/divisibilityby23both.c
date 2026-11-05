#include<stdio.h>
void main(void)
{
int n,a,b;
printf("Enter a number?");
scanf("%d",&n);
a=n%2;
b=n%3;
if((a==0)&&(b==0))
  printf("Number is divisible by both 2 and 3\n");
else if(a==0)
 printf("Number is divisible by 2\n");
else if(b==0)
   printf("Number is divisible by 3\n");
else
   printf("Number is not divisible by 2 and 3 both\n");
}
