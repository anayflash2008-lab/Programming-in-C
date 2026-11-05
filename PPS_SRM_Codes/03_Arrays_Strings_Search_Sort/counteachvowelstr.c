#include<stdio.h>
int main(void)
{
char st[100],vowel[20]="aeiouAEIOU";
int l1,l2,c=0;
printf("Enter a string?");
scanf("%[^\n]s",st);
for(l1=0;vowel[l1]!='\x0';l1++)
{
for(l2=0;st[l2]!='\x0';l2++)
{
if(vowel[l1]==st[l2])
 c++;
}
if(c!=0)
printf("%c occurs %d times in %s\n",vowel[l1],c,st);
c=0;
}
return 0;
}

