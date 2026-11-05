#include<stdio.h>
int main(void)
{
char st[30];
int i,j;
printf("Enter a String?");
scanf("%[^\n]s",st);
for(i=0;st[i]!='\x0';i++)
{
for(j=0;j<=i;j++)
 printf("%c",st[j]);
printf("\n");
}
return 0;
}

