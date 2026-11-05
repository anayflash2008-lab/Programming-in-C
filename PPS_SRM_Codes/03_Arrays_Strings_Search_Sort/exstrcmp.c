#include<string.h>
#include<stdio.h>
int main(void)
{
char st[40]="hello";
char st1[30]="hi";
printf("%d\n",strcmp(st1,st)); //4
printf("%d\n",strcmp(st,st1)); //-4
return 0;
}

