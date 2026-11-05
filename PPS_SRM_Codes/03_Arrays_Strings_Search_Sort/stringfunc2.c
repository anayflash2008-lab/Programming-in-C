#include<stdio.h>
#include<string.h>
int main(void)
{
char st1[20]="hello",st2[10]="SRM";
strcat(st1," ");
strcat(st1,st2);
printf("%s\n",st1);
return 0;
}

