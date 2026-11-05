#include<stdio.h>
int main(void)
{
int a,b,c;
printf("Enter 3 numbers?");
scanf("%d %d %d",&a,&b,&c);
if(((a*a)==(b*b)+(c*c))||((b*b)==(a*a)+(c*c))||((c*c)==(b*b)+(a*a)))
 printf("Pythagorean Triplets\n");
else
 printf("Not Pythagorean Triplets\n");
return 0;
}
 
