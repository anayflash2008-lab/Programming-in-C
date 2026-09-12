#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}
int main() {

    int ch;
    int (*p[4])(int, int);
    p[0] = add;
    p[1] = sub;
    p[2] = mul;
    p[3] = div;
    
        printf("1.Add\n2.Sub\n3.Mul\n4.Div\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
    if(ch > 0 && ch <= 4){
        printf("%d", p[ch-1](10, 5));
    }
    
    else{
        printf("Invalid Option");
    }

    return 0;
}