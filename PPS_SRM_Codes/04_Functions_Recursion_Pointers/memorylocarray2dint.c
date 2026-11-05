#include<stdio.h>
int main(void)
{
int a[2][2]={{1,2},{3,4}};
int j,k;
for(j=0;j<2;j++)
{
for(k=0;k<2;k++)
 printf("%d %p\t",a[j][k],&a[j][k]);
printf("\n");
}
return 0;
}
