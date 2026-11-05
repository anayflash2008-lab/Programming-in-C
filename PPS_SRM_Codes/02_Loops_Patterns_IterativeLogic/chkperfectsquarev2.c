#include<stdio.h>
#include<math.h>
int main(void)
{
int num,n;
scanf("%d",&num);
n=sqrt(num); //n=pow(num,0.5);
if(n*n==num)
 printf("Perfect Square\n");
else
 printf("Not a Perfect Square\n");
return 0;
}

