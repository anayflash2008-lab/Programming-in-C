#include<stdio.h>
void main(void)
{
char ch[30];
int n;
printf("Enter a word?");
scanf("%s",ch);
for(n=0;ch[n]!='\x0';n++);
for(;n>=0;n--)
 printf("%c",ch[n]);
printf("\n");
}

