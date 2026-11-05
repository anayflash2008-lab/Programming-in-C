#include<stdio.h>
void main(void)
{
int a;
for(a=1;a<=100;a++)
{
if((a%3==0)||(a%5==0)||(a%7==0))
  continue;
printf("%d\t",a);
}
}
