#include<stdio.h>
int main(void)
{
/*
****
*  *
*  *
****
*/
int n,i,j;
printf("Enter side of a Square?");
scanf("%d",&n);
for(i=0;i<n;i++)
{
if((i==0)||(i==(n-1))) //to print the first and last row
{
for(j=0;j<n;j++)
 printf("*");
}
else
{
printf("*");
for(j=0;j<n-2;j++)
printf(" ");
printf("*");
}
printf("\n");
}
return 0;
}

