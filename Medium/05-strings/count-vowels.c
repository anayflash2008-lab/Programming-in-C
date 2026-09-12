#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int i = 0 , cnt = 0; //count
    printf("Enter a string : ");
    fgets(str,100,stdin);
    while(str[i] != '\0'){
        char c = str[i];
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
          cnt++;
        i++;
    }
    printf("Number of Vowels : %d", cnt);
}