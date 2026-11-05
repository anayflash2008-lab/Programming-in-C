#include<stdio.h>
int main(void)
{
int r,c,i,o,t=0,q;
printf("How many rows?");
scanf("%d",&r);
for(o=r;o>=0;o--)
{
for(q=0;q<((t*2)-1);q++)
 printf(" ");
for(i=1;i<=((2*o)-1);i++)
{
printf("*");
}
t++;
printf("\n");
}
return 0;
}

