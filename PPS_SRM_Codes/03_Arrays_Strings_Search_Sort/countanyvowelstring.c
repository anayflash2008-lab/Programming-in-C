#include<stdio.h>
int main(void)
{
char st[30];
int loop,count=0;
printf("Enter a String?");
scanf("%[^\n]s",st);
for(loop=0;st[loop]!='\x0';loop++)
{
switch(st[loop])
{
case 'a':
case 'e':
case 'i':
case 'o':
case 'A':
case 'u':
case 'E':
case 'I':
case 'O':
case 'U':
 count++;
}
}
printf("There are %d vowels in %s\n",count,st);
return 0;
}

