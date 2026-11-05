#include<stdio.h>
void main(void)
{
int ch;
printf("Enter your choice?");
scanf("%d",&ch);
switch(ch)
{
//default:
// printf("Some other value than 1,2,or 3\n");
// break;
case 1:
 printf("One\n");
 break;
case 2:
 printf("Two\n");
 break;
case 3:
 printf("Three\n");
 break;
default:
printf("Value other than 1,2 or 3\n");
}
}

