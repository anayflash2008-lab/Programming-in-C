#include <stdio.h>
void calculateSum(int x , int y) {
  int sum = x + y;
  printf("The sum of x + y is: %d\n", sum);
}
void calculationSum() {
  int x, y;
  printf("Enter number 1 : ");
  scanf("%d",&x);  
  printf("Enter number 2 : ");
  scanf("%d",&y);

  int sum = x + y;
  printf("The sum of %d + %d is: %d\n", x, y, sum);
}

int main() {
  //calculationSum();  
  calculateSum(5, 3);
  calculateSum(8, 2);
  calculateSum(15, 15);
  calculationSum();

}