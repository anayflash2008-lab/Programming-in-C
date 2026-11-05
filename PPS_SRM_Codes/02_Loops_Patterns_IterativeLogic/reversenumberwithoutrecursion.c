/*num=123
n=num;
r=n%10
n=n/10*/
#include<stdio.h>
int main(void)
{
int num,n,r,reverse=0,sign=0;
scanf("%d",&num);
if(num<0)
{
 sign=1;
 n=num*(-1);
}
else
 n=num;
while(n>0)
{
r=n%10; //extract right most digit
printf("%d",r);
reverse=((reverse*10)+r);
n=n/10; //n/=10 remove rightmost digit
}
printf("\n");
if(sign==1)
 reverse=reverse*(-1);
printf("The reverse number is %d\n",reverse);
if(reverse==num)
 printf("Palindrome Number\n");
else
 printf("Not a Palindrome Number\n");
return 0;
}
