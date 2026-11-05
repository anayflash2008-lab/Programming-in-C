#include<stdio.h>
void main(void)
{
int year;
int r4;
int r100;
int r400;
printf("Enter year?");
scanf("%d",&year);
r4=year%4;
r100=year%100;
r400=year%400;
if(((r4==0)&&(r100!=0))||((r100==0)&&(r400==0)))
 printf("%d is a leap year\n",year);
else
 printf("%d is not a leap year\n",year);
}
