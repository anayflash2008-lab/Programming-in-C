#include<string.h>
#include<stdio.h>
int main(void)
{
char st1[]="hello",st2[30];
strcpy(st2,st1); //st2=st1 st2>st1 st2==st1->Invalid
printf("%s\n",st2);
return 0;
}
