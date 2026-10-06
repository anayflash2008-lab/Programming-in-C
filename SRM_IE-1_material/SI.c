#include <stdio.h>
int main(){
    float P,R,T,SI,AMT;
    scanf("%f %f %f",&P,&R,&T);
    SI = P*R*T/100;
    printf("%f",SI);
    AMT = P + SI;
    printf("\n%f",AMT);
}