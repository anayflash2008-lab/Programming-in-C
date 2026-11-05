#include<stdio.h>
int main(void)
{
int n[10];
int search;
int loop,count=0;
printf("Enter 10 numbers:\n");
for(loop=0;loop<10;loop++)
 scanf("%d",&n[loop]);
printf("Enter a number you want me to search?");
scanf("%d",&search);
for(loop=0;loop<10;loop++)
{
if(search==n[loop])
 count++;
}
printf("%d occurs %d times\n",search,count);
return 0;
}

