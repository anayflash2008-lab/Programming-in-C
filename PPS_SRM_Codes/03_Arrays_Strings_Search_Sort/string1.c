#include<string.h>
#include<stdio.h>
int main(void)
{
char st[30]="hello";
void func(char *str);
func(st);
printf("%s\n",st);
char *p=strstr(st,"ll");
if(p!=NULL)
printf("%c\n",*p);
else
printf("Not Found...");
return 0;
}
void func(char *str)
{
printf("%s",str);
printf("%c\n",str[0]);
str[0]='y';
}
