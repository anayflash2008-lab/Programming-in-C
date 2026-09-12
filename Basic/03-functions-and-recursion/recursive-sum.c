#include <stdio.h>
// sum of number in the form of n +(n-i)
int sum(int n) {
    if (n > 0) {
        return n + sum(n-1);
    }
    else {
        return 0;
    }
}

int main() {
    int n = 100;
    int res = sum(n);
    printf("The sum of first %d numbers is %d", n, res);
    return 0;
}