#include <stdio.h>

int main()
{
    float a, b, c;
    printf("Enter the three side lengths: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a <= 0 || b <= 0 || c <= 0){
        printf("Invalid triangle: Side lengths must be positive.\n");
    }
    else if (a + b <= c || a + c <= b || b + c <= a){
        printf("Invalid triangle: The given sides cannot form a triangle.\n");
    }
    else{
        printf("Valid triangle.\n");

        if (a == b && b == c)
        {
            printf("Triangle Type: Equilateral\n");
        }
        else if (a == b || b == c || a == c)
        {
            printf("Triangle Type: Isosceles\n");
        }
        else
        {
            printf("Triangle Type: Scalene\n");
        }
    }
}