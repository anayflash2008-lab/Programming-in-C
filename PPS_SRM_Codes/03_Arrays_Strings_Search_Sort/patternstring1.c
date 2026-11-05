#include<stdio.h>
int main(void)
{
char st[30];
int i,j,k;
printf("Enter a String?");
scanf("%[^\n]s",st);
for(i=0;st[i]!='\x0';i++);
for(j=i-1;j>=0;j--)
{
for(k=0;k<=j;k++)
{
 printf("%c",st[k]);
}
printf("\n");
}
return 0;
}

(a)
     *
    ***
   *****
  *******
(b)
*****
 ***
  *

