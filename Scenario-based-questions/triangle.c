/*A computer-aided civil engineering tool validates the stability of triangular truss frameworks. The user inputs the lengths of three fabricated steel beams: a, b, and c.
Questions:
Write an if...else if...else code segment that first validates if the three side lengths can physically form a valid triangle using the triangle inequality theorem (a+b>c, a+c>b, b+c>a). 
If valid, classify and display whether the frame structure is Equilateral, Isosceles, or Scalene. 
*/
#include <stdio.h>

int main()
{
    float a, b, c;
    printf("Enter the three side lengths: ");
    scanf("%f %f %f", &a, &b, &c);
    // Checking if the triangle exists or not
    if (a <= 0 || b <= 0 || c <= 0){
        printf("Invalid triangle: Side lengths must be positive.\n");
    }
    else if (a + b <= c || a + c <= b || b + c <= a){
        printf("Invalid triangle: The given sides cannot form a triangle.\n");
    }
    else{
        printf("Valid triangle.\n");
        // Type of triangles
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