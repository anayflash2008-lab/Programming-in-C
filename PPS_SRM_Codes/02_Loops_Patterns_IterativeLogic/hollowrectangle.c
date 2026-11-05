#include<stdio.h>
int main(void)
{
/*
*****
*   *
*   *
*****
*/
int n,m,i,j;
printf("Enter length and breadth of a Rectangle?");
scanf("%d %d",&n,&m);
for(i=0;i<m;i++)
{
if((i==0)||(i==(m-1))) //to print the first and last row
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

