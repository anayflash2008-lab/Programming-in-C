/*
1 2 3   <-Rows  |
4 5 6	       Col
7 8 9


int a[3][3]
a[0][0]=1
a[0][1]=2
a[0][2]=3
a[1][0]=4
a[1][1]=5
a[1][2]=6
a[2][0]=7
a[2][1]=8
a[2][2]=9
*/
#include<stdio.h>
void main(void)
{
int a[10][10],b[10][10],row,col,c[10][10],i,j;
printf("Enter dimentions of matrices?");
scanf("%d %d",&row,&col);
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
printf("Enter A[%d][%d]?",i,j);
scanf("%d",&a[i][j]);
printf("Enter B[%d][%d]?",i,j);
scanf("%d",&b[i][j]);
c[i][j]=a[i][j]+b[i][j];
}
}
printf("Matrix Addition is:\n");
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n");
}
printf("\n");
}

