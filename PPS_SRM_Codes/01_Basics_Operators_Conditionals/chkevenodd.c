#include<stdio.h>
void main(void)
{
int a,b;
printf("Enter a number you want me to check for even or odd?");
scanf("%d",&a);
b=a%2;
if(b==0)
 printf("Number is Even\n");
else
 printf("Number is Odd\n");
}

