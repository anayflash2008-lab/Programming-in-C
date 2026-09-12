#include <stdio.h>

int main() {
  int ar[5] = {25, 50, 75, 100, 125};
  int i;
// Printing Memory address of each and every Value of the given Array
  for (i = 0; i < 5; i++) {
    printf("%x\n", &ar[i]); //hx
  }
}