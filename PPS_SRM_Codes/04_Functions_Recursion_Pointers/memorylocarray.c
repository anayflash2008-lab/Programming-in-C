#include<stdio.h>
int main(void)
{
int a[10]={1,2,3,4,5,6,7,8,9,10};
int l;
for(l=0;l<10;l++)
printf("%d %p\n",a[l],&a[l]);//memory allocation
return 0;//is contiguous
}


