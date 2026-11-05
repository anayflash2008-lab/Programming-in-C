#include<stdio.h>
int main(void)
{
int m,n;
printf("Enter Order of Matrices?");
//scanf("%d %d",&m,&n);
int a[m][n],b[m][n],c[m][n];
scanf("%d %d",&m,&n);
int i,j;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("Enter a[%d][%d]?",i,j);
scanf("%d",&a[i][j]);
printf("Enter b[%d][%d]?",i,j);
scanf("%d",&b[i][j]);
c[i][j]=a[i][j]+b[i][j];
}
}
printf("The addition of matrices is:\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
 printf("%d\t",c[i][j]);
printf("\n");
}
return 0;
}
