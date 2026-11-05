#include<string.h>
#include<stdio.h>
int main(void)
{
char st[30];
int l=0;
printf("Enter a String?");
scanf("%[^\n]s",st);
l=strlen(st);//for(l=0;st[l]!='\x0';l++);
/*while(st[l]!='\x0')
{
 l++;
}*/
l=l-1;
printf("Reverse of the String %s is :",st);
while(l>=0)
{
 printf("%c",st[l]);
 l--;
}
printf("\n");
return 0;
}
