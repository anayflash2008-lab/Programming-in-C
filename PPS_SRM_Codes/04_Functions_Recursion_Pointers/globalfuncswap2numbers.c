#include<stdio.h>

int main(void)
{
extern int a,b;
void swap(void);
scanf("%d %d",&a,&b);
swap();
printf("In main %d %d\n",a,b);
return 0;
}
int a,b;
void swap(void)
{
//extern int a,b;
int c;
c=a;
a=b;
b=c;
printf("In function %d %d\n",a,b);
}
