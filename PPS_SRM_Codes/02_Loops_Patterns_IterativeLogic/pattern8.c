#include<stdio.h>
void main(void)
{
int n;
int o,i;
char ch='+';
printf("Enter how many lines you want to print?");
scanf("%d",&n);
for(o=1;o<=n;o++)
{
for(i=1;i<=o;i++)
{
 printf("%c",ch);
 if(ch=='+')
   ch='-';
 else 
   ch='+';
}
printf("\n");
}
}

