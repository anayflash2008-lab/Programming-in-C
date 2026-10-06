#include <stdio.h>

int main() {
    int amt;
    int n500 = 0, n200 = 0, n100 = 0, n50 = 0;
    int n20 = 0, n10 = 0, n5 = 0, n2 = 0, n1 = 0;

    scanf("%d", &amt);

    if (amt < 0) {
        printf("Error");
        return 0;
    }

    while (amt > 0) {

        if (amt >= 500) {
            amt = amt - 500;
            n500++;
            printf("500 subtracted, remaining amount = %d\n", amt);
        }
        else if (amt >= 200) {
            amt = amt - 200;
            n200++;
            printf("200 subtracted, remaining amount = %d\n", amt);
        }
        else if (amt >= 100) {
            amt = amt - 100;
            n100++;
            printf("100 subtracted, remaining amount = %d\n", amt);
        }
        else if (amt >= 50) {
            amt = amt - 50;
            n50++;
            printf("50 subtracted, remaining amount = %d\n", amt);
        }
        else if (amt >= 20) {
            amt = amt - 20;
            n20++;
            printf("20 subtracted, remaining amount = %d\n", amt);
        }
        else if (amt >= 10) {
            amt = amt - 10;
            n10++;
            printf("10 subtracted, remaining amount = %d\n", amt);
        }
        else if (amt >= 5) {
            amt = amt - 5;
            n5++;
            printf("5 subtracted, remaining amount = %d\n", amt);
        }
        else if (amt >= 2) {
            amt = amt - 2;
            n2++;
            printf("2 subtracted, remaining amount = %d\n", amt);
        }
        else {
            amt = amt - 1;
            n1++;
            printf("1 subtracted, remaining amount = %d\n", amt);
        }
    }

    printf("\n--- Number of each money ---\n");
    printf("500 = %d\n", n500);
    printf("200 = %d\n", n200);
    printf("100 = %d\n", n100);
    printf("50  = %d\n", n50);
    printf("20  = %d\n", n20);
    printf("10  = %d\n", n10);
    printf("5   = %d\n", n5);
    printf("2   = %d\n", n2);
    printf("1   = %d\n", n1);
}