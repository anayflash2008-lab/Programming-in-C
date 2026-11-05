#include<stdio.h>
void main(void)
{
int age;
printf("Enter your age?");
scanf("%d",&age);
if((age>0)&&(age<=120))
{
if(age>=18)
 printf("You can vote\n");
else
 printf("You are too young to vote\n");
}
else
 printf("Enter correct age\n");
}

