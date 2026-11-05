#include<time.h>
#include<stdio.h>
int main(void)
{
clock_t c=clock();
printf("Hi\n");
clock_t c1=clock();
printf("Difference=%ld\n",c1-c);
return 0;
}
