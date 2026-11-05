#include<stdio.h>
void main(void)
{
char st[100];
int n;
int o,i;
printf("Enter your name?");
scanf("%s",st);
for(n=0;st[n]!='\x0';n++);
for(o=0;o<n;o++)
{
for(i=0;i<=o;i++)
{
 printf("%c",st[i]);
}
printf("\n");
}
}

