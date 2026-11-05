#include<stdio.h>
void main(void)
{//const pi=22.0/7; Implicit data type conversion
const float pi=(float)22/7; //Explicit data type conversion
float radius; //A keyword is a reserved word in C i.e it has a 
float area,peri;//special meaning
printf("Enter Radius?");
scanf("%f",&radius);
peri=(pi*radius*2);
area=(pi*radius*radius);
printf("Area %f Perimeter %f\n",area,peri);
}
