#include<stdio.h>
int main(void)
{
int r,c,i,o;
printf("Enter rows and columns for the graphic?");
scanf("%d %d",&r,&c);
for(o=1;o<=r;o++)
{
for(i=o;i>=1;i--)
{
 printf("*");
}
printf("\n");
}
return 0;
}

