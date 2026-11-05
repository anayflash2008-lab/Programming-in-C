#include<stdio.h>
void main(void)
{
char nam[30];
int n;
printf("Enter your name?");
scanf("%[^\n]s",nam);
for(n=0;nam[n]!='\x0';n++)
printf("%c\n",nam[n]);
}
/*
nam="AMIT"
nam[0]='A'
nam[1]='M'
nam[2]='I'
nam[3]='T'
nam[4]='\x0'
NULL means end of string
*/
