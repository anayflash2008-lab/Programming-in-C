#include <stdio.h>
#include <stdbool.h>
int main() {
    int age = 20;
bool isCitizen = false;

if (age >= 18) {
  printf("Old enough to vote.\n");

  if (isCitizen) {
    printf("And you are a citizen, so you can vote!\n");
  } else {
    printf("But you must be a citizen to vote.\n");
  } 
} else {
  printf("Not old enough to vote.\n");
}
}