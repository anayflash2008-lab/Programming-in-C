#include <stdio.h>
int main(){
    int num = 120304, temp;
    int sum = 0;
    temp = num;
    while (temp>0){
        sum = (sum * 10) + (temp % 10);
        temp = temp/10;
    }
    num = sum;
    printf("%d",num);
}