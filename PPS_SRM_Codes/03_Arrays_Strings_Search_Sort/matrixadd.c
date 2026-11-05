#include<stdio.h>
int main(void)
{
int m,n;
int a[100][100],b[100][100],sumc[100][100];
scanf("%d %d",&m,&n);
for(int r=0;r<m;r++)
{
for(int c=0;c<n;c++)
{
printf("a[%d][%d]?",r,c);
scanf("%d",&a[r][c]);
printf("b[%d][%d]?",r,c);
scanf("%d",&b[r][c]);
sumc[r][c]=a[r][c]+b[r][c];
}
}
printf("Sum=\n");
for(int r=0;r<m;r++)
{
for(int c=0;c<n;c++)
{
 printf("%d\t",sumc[r][c]);
}
printf("\n");
}
//int a[2][2];
return 0;
}
