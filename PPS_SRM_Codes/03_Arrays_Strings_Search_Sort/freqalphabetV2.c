#include<stdio.h>
int main(void)
{
char alphabets[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char st[40];
int count=0;
printf("Enter a String?");
scanf("%[^\n]s",st);
for(int s=0;alphabets[s]!='\x0';s++)
{
for(int t=0;st[t]!='\x0';t++)
{
if(alphabets[s]==st[t])
 count++;
}
if(count!=0)
 printf("There are %d occurences of %c\n",count,alphabets[s]);
count=0;
}
return 0;
}

