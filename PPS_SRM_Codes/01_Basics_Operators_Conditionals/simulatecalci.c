#include<stdio.h>
#include<stdlib.h>
void main(void)
{
float a,b,result;
char dummy,ch;
printf("Enter two numbers?");
scanf("%f %f",&a,&b);
printf("Enter your choice (+ Add,- Substract,* Multiply,/ Divide)?");
scanf("%c",&dummy);
scanf("%c",&ch);
switch(ch)
{
case '+':
result=a+b;
break;
case '-':
result=a-b;
break;
case '*':
result=a*b;
break;
case '/':
result=a/b;
break;
default:
printf("Invalid choice..\n");
exit(0); //End the program ->abnormal termination
}
printf("Result is %f\n",result);
}

