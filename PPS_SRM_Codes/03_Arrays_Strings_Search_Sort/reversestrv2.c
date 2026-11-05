#include<string.h>
#include<stdio.h>
int main(void)
{
char st[30],st1[30];
int l,m,n;
printf("Enter a String?");
scanf("%[^\n]s",st);
for(l=0;st[l]!='\x0';l++);
for(m=l-1,n=0;m>=0;m--,n++)
{
 st1[n]=st[m];
}
st1[n]='\x0';
printf("The reversed string is %s\n",st1);
//if(st!=st1) will not work
if(strcmp(st,st1)==0)
 printf("String %s is a palindrome\n",st);
else
 printf("String %s is not a palindrome\n",st);
return 0;
}

