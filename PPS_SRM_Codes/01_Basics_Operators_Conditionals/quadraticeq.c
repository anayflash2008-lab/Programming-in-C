#include<stdio.h>
#include<math.h>
void main(void)
{
float a,b,c,d,r1,r2;
printf("Enter cooefficients A,B and C?");
scanf("%f %f %f",&a,&b,&c);
d=(b*b)-(a*c*4);
if(d<0)
 printf("Roots are Imaginary\n");
else if(d==0)
 {
   r1=-b/(a*2);
   printf("Roots are same %f\n",r1);
 }
else
 {
  r1=(-b+sqrt(d))/(a*2); //pow(d,.5)
  r2=(-b-sqrt(d))/(a*2);
  printf("Roots are Real and Distinct %f %f\n",r1,r2);
 }
}

