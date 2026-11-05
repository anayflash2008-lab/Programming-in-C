#include<stdio.h>
void main(void)
{
int a[10][10],row,col,t[10][10],i,j;
printf("Enter dimentions of matrices?");
scanf("%d %d",&row,&col);
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
printf("Enter A[%d][%d]?",i,j);
scanf("%d",&a[i][j]);
t[j][i]=a[i][j];
}
}
printf("Matrix Transpose is:\n");
for(i=0;i<col;i++)
{
for(j=0;j<row;j++)
{
printf("%d\t",t[i][j]);
}
printf("\n");
}
printf("\n");
}

