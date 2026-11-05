#include<stdio.h>
int main(void)
{
int maxelement(int *,int );
int arr[5]={32,115,2,54,23};
printf("%d\n",maxelement(&arr[0],5));
return 0;
}
int maxelement(int *num,int size)
{
int d;
static int g;
if(size==1)
 return g;
if(*(num)>*(num+1))
  g=*num;
else
  g=*(num+1);
d=maxelement(++num,--size);
}
