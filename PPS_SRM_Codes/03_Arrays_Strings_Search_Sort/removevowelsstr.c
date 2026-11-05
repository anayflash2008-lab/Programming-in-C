#include<stdio.h>
#include<string.h>
int main(void)
{
char st[30],nst[30];
int i,j=0;
printf("Enter a String?");
scanf("%[^\n]s",st);
for(i=0;st[i]!='\x0';i++)
{
if(!((st[i]=='a')||(st[i]=='e')||(st[i]=='o')||(st[i]=='i')||(st[i]=='u')))
{
 nst[j]=st[i];
 j++;
}
}
nst[j]='\x0';
//st=nst; -> Invalid
/*for(j=0;nst[j]!='\x0';j++)
 st[j]=nst[j];
st[j]='\x0';*/
strcpy(st,nst);
printf("The string without vowels is: %s\n",st);
return 0;
}

