#include<stdio.h>
int main(void)
{
int ar[]={1,2,3,1,21,2,43,34,12,1,4,2,4};
int s=sizeof(ar)/sizeof(int);
int a,b,c,flag=0,count=0;
for(a=0;a<s;a++)
{
//Search backwards
for(c=0;c<a;c++)
{
if(ar[a]==ar[c])
{
 flag=1;
 break;
}
}
if(flag==0)
{
for(b=0;b<s;b++)
{
if(ar[a]==ar[b])
 count++;
}
printf("%d occurs %d times\n",ar[a],count);
}
flag=0;
count=0;
}
return 0;
}

