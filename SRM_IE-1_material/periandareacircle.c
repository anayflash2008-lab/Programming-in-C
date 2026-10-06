#include <stdio.h>
#include <math.h>

int main()
{
    float r, peri, area;
    scanf("%f", &r);
    peri = 2 * 3.1416 * r;
    area = 3.1416 * r * r;
    printf("%f\n%f", peri, area);
}