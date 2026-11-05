#include<stdio.h>
void main(void)
{
char nam[30]; //String of 30 characters
printf("Enter your name?");
scanf("%[^\n]s",nam);
printf("Hello %c\n",nam[2]);
}

