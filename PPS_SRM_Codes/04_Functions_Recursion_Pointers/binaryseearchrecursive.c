#include<stdio.h>
int bsearch(int a[],int beg,int end,int search)
{
if(beg>end)
 return -1;
int mid=beg+(end-beg)/2;
if(a[mid]==search)
 return mid;
else if(a[mid]>search)
return  bsearch(a,beg,mid-1,search);
else
return bsearch(a,mid+1,end,search);
}
int main(void)
{
int bsearch(int [],int,int,int);
int arr[7]={1,2,3,4,5,6,7};
int s;
scanf("%d",&s);
int r=bsearch(arr,0,6,s);
if(r==-1)
 printf("Element not found\n");
else
 printf("Element found at IDX %d",r);
return 0;
}
