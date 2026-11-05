#include<stdio.h>
int main(void)
{
int a[]={7,6,5,4,3,2,1};
int s=sizeof(a)/sizeof(int); //count of array
for(int i=0;i<s;i++)
{
for(int j=i+1;j<s;j++)
{
if(a[i]>a[j])
{
int temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("Sorted Elements are:\n");
for(int i=0;i<s;i++)
 printf("%d ",a[i]);
printf("\n");
return 0;
}

