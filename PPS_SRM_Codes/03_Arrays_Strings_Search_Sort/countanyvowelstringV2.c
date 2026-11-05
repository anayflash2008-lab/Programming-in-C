#include<stdio.h>
int main(void)
{
char st[100],vow[20]="aeiouAEIOU";
int loop,count=0;
scanf("%[^\n]s",st);
for(loop=0;st[loop]!='\x0';loop++)
{
for(int l=0;vow[l]!='\x0';l++)
{
 if(st[loop]==vow[l])
  {
   count++;
   break;
  }
}
}
printf("Vowels occur %d times in %s\n",count,st);
return 0;
}
