#include<stdio.h>
int main(void)
{
int l1,l2,c=0;
char st[100];
char vowel[20]="aeiouAEIOU";
printf("Enter a String?");
scanf("%[^\n]s",st);
for(l1=0;vowel[l1]!='\x0';l1++)
{
for(l2=0;st[l2]!='\x0';l2++)
{
if(vowel[l1]==st[l2])
 c++;
}
if(c!=0)
printf("There are %d %c in %s\n",c,vowel[l1],st);
c=0;
}
return 0;
}

