#include<stdio.h>
int main(void)
{
int a,b; //a=3 b=4
scanf("%d %d",&a,&b);
a=a+b;//a=7
b=a-b;//b=7-4=3
a=a-b;//a=7-3=4
printf("%d %d\n",a,b);
return 0;
}

