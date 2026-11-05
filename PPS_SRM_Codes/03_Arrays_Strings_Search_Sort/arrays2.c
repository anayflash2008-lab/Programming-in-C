#include<stdio.h>
int main(void)
{
char st[100];
char search,dummy;
int loop,count=0;
printf("Enter a string?");
scanf("%[^\n]s",st);
scanf("%c",&dummy);
printf("Enter a character you want me to search?");
scanf("%c",&search);
for(loop=0;st[loop]!='\x0';loop++)
{
if(search==st[loop])
 count++;
}
printf("%c occurs %d times in %s\n",search,count,st);
return 0;
}

