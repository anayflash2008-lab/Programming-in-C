#include <stdio.h>

struct Rectangle {
    int length;
    int breadth;
};

int main() {

    struct Rectangle r;

    printf("Enter length and breadth: ");
    scanf("%d%d", &r.length, &r.breadth);

    int area = r.length * r.breadth;

    printf("Area = %d", area);

    return 0;
}