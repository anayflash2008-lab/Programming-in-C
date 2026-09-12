#include <stdio.h>
float tCel(float f) {
  return (5.0 / 9.0) * (f - 32.0);
}

int main() {
  float fval = 0;
  float res = tCel(fval);
  printf("Fahrenheit: %.2f\n", fval);
  printf("Convert Fahrenheit to Celsius: %.2f\n", res);   
}