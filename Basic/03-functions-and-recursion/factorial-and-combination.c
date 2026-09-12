#include <stdio.h>
int fact(int n){
    int f = 1;
    for(int i = 1; i <= n; i++) {
        f = f*i;
    }
    return f;    
}
int main(){
    int n,r;
    printf("Enter n & r : ");
    scanf("%d %d", &n , &r);
    float a;
    a = fact(n)/(fact(n-r) * fact(r));
    printf("The Combination where n = %d and r = %d = %f",n,r,a);
}