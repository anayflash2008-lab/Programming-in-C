#include<stdio.h>
int main(void)
{
int a;
for(a=1;a<=20;a++)
{
if(a%4==0)
 continue;
printf("%d\n",a);
}
return 0;
}
