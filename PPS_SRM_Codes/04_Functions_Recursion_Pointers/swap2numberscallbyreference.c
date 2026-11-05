#include<stdio.h>
int main(void)
{
void swap(int *,int *);
int a,b;
scanf("%d %d",&a,&b);
swap(&a,&b);
printf("%d %d\n",a,b);
return 0;
}
void swap(int *p,int *q)
{
int c;
c=*p;
*p=*q;
*q=c;
}

