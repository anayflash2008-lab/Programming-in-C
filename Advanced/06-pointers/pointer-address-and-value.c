#include <stdio.h>

int main() {
  int Age = 43;  // An int variable
  int *a;  // A pointer variable, with the name a, that stores the address of Age
  a = &Age;  

  // Output the value of Age in terms of *a
  printf("%d\n", *a);

  // Output the memory address of Age with the pointer a
  printf("%p\n", a); // Binary
  printf("%x\n",a); // Hexadecimal
  // Modifying Age using Pointer a
  /*printf("Enter a number :");
  scanf("%d",&*a);*/
  printf("The Modified age is : %d",Age); 
}