#include<stdio.h>
int main(void)
{
int a[8]={1,2,3,4,5,6,7};
int beg=0,end=6,mid;
int search;
int flag=0;
scanf("%d",&search);
while(beg<=end)
{
mid=(beg+end)/2;
if(a[mid]==search)
{
printf("Element found at idx %d\n",mid);
flag=1;
break;
}
else if(a[mid]>search)
end=mid-1;
else
beg=mid+1;
}
if(flag==0)
 printf("Element Not Found\n");
return 0;
}

