#include <stdio.h>
#include <math.h>
int main(){
    float a,b,c,r1,r2,d;
    scanf("%f %f %f",&a,&b,&c);
    printf("Quadratic equation -> %.2fx^2+%.2fx+%.2f = 0\n",a,b,c);
    d = b*b - 4*a*c;
    if(d<0){
        printf("Roots are imaginary");
    }
    else if(d == 0){
        printf("Roots are real and equal");
        r1 = -b/(2*a);
        r2 = r1;
        printf("Roots of the equation are :-\n r1 : %.2f, r2 : %.2f",r1,r2);
    }
    else{
        printf("roots are real and distinct");
        r1 = (-b+sqrt(d))/(2*a);
        r2 = (-b-sqrt(d))/(2*a);
        printf("Roots of the equation are :-\n r1 : %.2f, r2 : %.2f",r1,r2);
    }
    
}