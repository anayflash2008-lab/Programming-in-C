#include<stdio.h>
int main(void)
{
int length(char *p);
char st[10]="hello";
printf("%d\n",length(&st[0]));
return 0;
}
int length(char *p)
{
int d;
static int c;
if (*p=='\x0')
 return c;
else 
{
c++;
d=length(++p);
}
}
