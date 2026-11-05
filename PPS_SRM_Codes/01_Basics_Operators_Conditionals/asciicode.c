#include<stdio.h>
void main(void)
{
char ch='A';
for(;ch<='Z';ch++)
printf("%c %d\n",ch,ch); //Implicit data type conversion
ch='a';
printf("%c %d\n",ch,ch);
ch='0';
printf("%c %d\n",ch,ch);
ch=' ';
printf("%c %d\n",ch,ch);
}

