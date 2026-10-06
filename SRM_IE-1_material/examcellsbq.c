#include <stdio.h>
int main(){
    float max = 100;
    float phy,chem,math;
    float total,avg,perc;
    scanf("%f %f %f",&phy,&chem,&math);
    if((phy < 0 || phy > 100) || (chem < 0 || chem > 100 ) || (math < 0 || math > 100)){
        printf("Invalid marking");
    }
    total = phy+chem+math;
    avg = total / 3;
    perc = avg * 100 / max;
    printf("Percentage : %.2f\n",perc);
    if(avg >= 90){
        printf("Outstanding");
    }
    else if(avg < 90 && avg >= 60){
        printf("First Class");
    }
    else{
        printf("Fail");
    }

}