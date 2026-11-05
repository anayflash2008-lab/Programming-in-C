#include<stdio.h>
int main(void)
{
int m,n,i,j;
printf("Enter order of the matrix?");
scanf("%d %d",&m,&n);
int a[m][n],b[n][m];
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("Enter a[%d][%d]?",i,j);
scanf("%d",&a[i][j]);
b[j][i]=a[i][j];
}
}
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("%d\t",b[i][j]);
}
printf("\n");
}
return 0;
}
