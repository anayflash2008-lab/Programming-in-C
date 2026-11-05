#include<stdio.h>
int main(void)
{
char st[50];
int count=0,Ucount=0;
printf("Enter a String?");
scanf("%[^\n]s",st);
for(char ch='a', Uch='A';ch<='z';ch++,Uch++)
{
for(int l=0;st[l]!='\x0';l++)
{
if(ch==st[l])
 count++;
if(Uch==st[l])
 Ucount++;
}
if(count!=0)
 printf("%c occurs %d times\n",ch,count);
if(Ucount!=0)
 printf("%c occurs %d times\n",Uch,Ucount);
count=0;
Ucount=0;
}
return 0;
}
