#include<stdio.h>
int main(void)
{
int ar[]={1,2,4,1,4,2,5,7,8,9,6,1};
int s=sizeof(ar)/sizeof(int),c,b,a;
int flag=0,count=0;
printf("There are %d elements in the array\n",s);
for(a=0;a<s;a++)
{
//printf("Searching for %d\n",ar[a]);
//Search backwards
for(b=0;b<a;b++)
{
if(ar[a]==ar[b])
{
flag=1;
break;
}
}
if(flag==0)
{
for(c=a;c<s;c++)
{
if(ar[c]==ar[a])
 count++;
}
printf("%d occurs %d times\n",ar[a],count);
}
flag=0;
count=0;
}
return 0;
}
