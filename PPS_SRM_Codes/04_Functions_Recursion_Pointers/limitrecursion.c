#include<stdio.h>
int main(void)
{
void recursion(void);
recursion();
return 0;
}
void recursion(void)
{
static int c=0;
printf("In func and times %d\n",++c);
recursion();
}
