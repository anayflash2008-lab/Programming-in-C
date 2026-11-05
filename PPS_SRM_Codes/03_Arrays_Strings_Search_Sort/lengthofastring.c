/*
a="hello"
a[0]='h'
a[1]='e'
a[2]='l'
a[3]='l'
a[4]='o'
a[5]='\x0'
*/
#include<stdio.h>
int main(void)
{
char st[30];
int i;
printf("Enter a String?");
scanf("%[^\n]s",st);
for(i=0;st[i]!='\x0';i++);
printf("Length of %s is %d\n",st,i);
return 0;
}

