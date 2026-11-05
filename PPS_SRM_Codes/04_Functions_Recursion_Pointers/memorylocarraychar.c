#include<stdio.h>
int main(void)
{
char s[10]="hello";
int l;
for(l=0;s[l]!='\x0';l++)
printf("%c %d %p\n",s[l],s[l],&s[l]);
return 0;
}
