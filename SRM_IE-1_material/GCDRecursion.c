#include <stdio.h>
int GCD(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return GCD(b,a%b);
    }
}

int main(){
    int A,B,hcf;
    scanf("%d %d", &A,&B);
    if(B > A){
        hcf = GCD(B,A);
    }
    else{
        hcf = GCD(A,B);
    }
    printf("%d",hcf);
}