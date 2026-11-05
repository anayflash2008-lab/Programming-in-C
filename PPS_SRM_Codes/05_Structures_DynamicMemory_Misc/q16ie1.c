#include<stdio.h>
int main(void)
{
float c,f,k;
void converttemp(float,float *, float *);
scanf("%f",&c);
converttemp(c,&f,&k);
printf("Temp is Deg F and Deg K are %f and %f\n",f,k);
return 0;
}
void converttemp(float dc,float *df,float *dk)
{
*df=((9.0/5)*dc)+32;
*dk=dc+273.15;
}

