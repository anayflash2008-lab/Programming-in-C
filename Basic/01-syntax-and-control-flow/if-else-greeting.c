#include <stdio.h>
#include <stdbool.h>
int main() {
/*    int time = 16;

if (time < 12) {
  printf("Good morning.");
} else if (time < 18) {
  printf("Good day.");
} else {
  printf("Good evening.");
} */
int time = 16;

bool isMorning = time < 12;
bool isDay = time < 18;

if (isMorning) {
  printf("Good morning.");
} else if (isDay) {
  printf("Good day.");
} else {
  printf("Good evening.");
}
    return 0;
}