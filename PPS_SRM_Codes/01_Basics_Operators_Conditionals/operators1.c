#include<stdio.h>
int main(void)
{
int a,b,c;
scanf("%d %d",&a,&b);
/*
if(a>b)
 c=a;
else
 c=b;
*/
c=(a>b)?a:b; //ternary operator ?:
printf("%d\n",c);
a=4;
a*=4; //a=a*4; Shorthand operators
a+=4; //a=a+4;
a/=4; //a=a/4;
a-=4; //a=a-4;
return 0;
}

