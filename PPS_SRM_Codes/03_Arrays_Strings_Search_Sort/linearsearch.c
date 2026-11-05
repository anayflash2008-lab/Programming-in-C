#include<stdio.h>
int main(void)
{
int a[10];
int search;
int loop,count=0;
printf("Enter elements of the array?\n");
for(loop=0;loop<10;loop++)
 scanf("%d",&a[loop]);
printf("Enter element you want me to search?");
scanf("%d",&search);
for(loop=0;loop<10;loop++)
{
if(search==a[loop])
  count++;
}
if(count==0)
 printf("Element not found\n");
else
 printf("%d occurs %d times in the array\n",search,count);
return 0;

}

