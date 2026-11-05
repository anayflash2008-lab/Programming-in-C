#include<stdio.h>
int main(void)
{
int reverse(int,int);
int number;
scanf("%d",&number);
printf("The reverse of %d is %d\n",number,reverse(number,0));
return 0;
}
int reverse(int n,int r)
{
int d;
if(n==0)
 return r;
else
d=reverse(n/10,((r*10)+(n%10)));
}
