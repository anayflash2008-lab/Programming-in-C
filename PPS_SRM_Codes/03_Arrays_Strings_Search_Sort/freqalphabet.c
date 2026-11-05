#include<stdio.h>
int main(void)
{
int freq=0,Zfreq=0;
char ch,Zch;
char st[40];
printf("Enter a String?");
scanf("%[^\n]s",st);
for(Zch='A',ch='a';ch<='z';ch++,Zch++)
{
for(int s=0;st[s]!='\x0';s++)
{
if(ch==st[s])
 freq++;
if(Zch==st[s])
 Zfreq++;
}
if(freq!=0)
printf("There are %d occurences of %c\n",freq,ch);
if(Zfreq!=0)
printf("There are %d occurences of %c\n",Zfreq,Zch);
freq=0;
Zfreq=0;
}
return 0;
}

