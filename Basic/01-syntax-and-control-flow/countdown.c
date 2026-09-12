#include <stdio.h>
int main() {
    int count;
    printf("Enter a number to start the countdown: ");
    scanf("%d", &count);

    printf("Countdown:\n");
    for (int i = count; i >= 0; i--) {
        printf("%d\n", i);
    }

    printf("Liftoff!\n");
    return 0;
}