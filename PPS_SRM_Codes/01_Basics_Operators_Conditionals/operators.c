#include<stdio.h>
int main(void)
{
int a,b,c;
a=3;
b;
c;
b=a++; //b=3 a=4
c=++a;//c=5 a=5
printf("%d %d %d\n",a,b,c);
b=a--;//b=5 a=4
c=--a;//a=3 c=3
printf("%d %d %d\n",a,b,c);
return 0;
}

