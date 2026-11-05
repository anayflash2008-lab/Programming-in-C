#include<stdio.h>
#include<string.h>
int main(void)
{
char st[30];
scanf("%[^\n]s",st);
strrev(st);
printf("Reversed String is %s\n",st);
return 0;
}

