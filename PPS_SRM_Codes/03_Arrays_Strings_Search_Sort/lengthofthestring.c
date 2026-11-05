/*
st="hello"
st[0]='h'
st[1]='e'
st[2]='l'
st[3]='l'
st[4]='o'
st[5]='\x0'
*/
#include<string.h>
#include<stdio.h>
int main(void)
{
char st[30];
int p;
printf("Enter a String?");
scanf("%[^\n]s",st);
p=strlen(st); //for(p=0;st[p]!='\x0';p++);
printf("String has %d chars\n",p);
return 0;
}

