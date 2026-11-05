#include<stdio.h>
int main(void)
{
int reverse(int,int);
int num;
scanf("%d",&num);
if(num%10!=0)
printf("%d\n",reverse(num,0));
else
printf("0%d\n",reverse(num,0));
return 0;
}
int reverse(int x,int r)
{
int d=0;
if(x==0)
 return r;
else
d=reverse(x/10,(r*10)+x%10);
}
