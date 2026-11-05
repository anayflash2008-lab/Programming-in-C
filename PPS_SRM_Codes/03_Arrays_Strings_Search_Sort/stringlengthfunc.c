#include<stdio.h>
int main(void)
{
void strlen(char *s);
char str[30];
scanf("%[^\n]s",str);
strlen(str);
return 0;
}
void strlen(char *s)
{
int i;
for(i=0;s[i]!='\x0';i++);
printf("%d\n",i);
}
