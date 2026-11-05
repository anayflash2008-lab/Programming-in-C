#include<stdio.h>
void main(void)
{
char ch='a';
char st[100];
int l,freq=0;
printf("Enter a string in lower case please?");
scanf("%[^\n]s",st);
for(;ch<='z';ch++)
{
for(l=0;st[l]!='\x0';l++)
{
if(st[l]==ch)
 freq++;
}
if(freq!=0)
 printf("I found %d %c in the string\n",freq,ch);
freq=0;
}
}
