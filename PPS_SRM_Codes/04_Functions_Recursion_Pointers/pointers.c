#include<stdio.h>
int main(void)
{
int a=3;
int *p;
p=&a;
printf("%d\n",a);
printf("%d\n",*p);
printf("%p\n",p);
printf("%p\n",&a);
printf("%p\n",&p);
return 0;
}

