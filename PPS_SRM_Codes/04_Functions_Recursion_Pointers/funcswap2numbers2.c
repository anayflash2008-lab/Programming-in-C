#include<stdio.h>
int main(void)
{
int a,b;
void swap(int *,int *);
scanf("%d %d",&a,&b);
swap(&a,&b);
printf("In main %d %d\n",a,b);
return 0;
}
void swap(int *x,int *y)
{
int c;
c=*x;
*x=*y;
*y=c;
printf("%d %d\n",*x,*y);
}

