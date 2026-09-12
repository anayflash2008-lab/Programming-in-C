#include <stdio.h>
#include <string.h>

int main() {
    int a = 10;
    char *b;
  /*  printf("value = %d address = %x",a,&a);
    b = &a;
    printf("\nvalue = %d value - %x",*b,b);
    *b = 50;
    printf("value = %d address = %x",a,&a);
    b = (int *) 0x5fdfdf;
    *b = 1000;
     printf("\nvalue = %d value - %x",*b,b);*/
     b = (char *) &a;
     for(int i=1;i< 10000;i++)
     {
         printf("%c",*(b-i));
         *(b-i) = 0;
     }


    return 0;
}