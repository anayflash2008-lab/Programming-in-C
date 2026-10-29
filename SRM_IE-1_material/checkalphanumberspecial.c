#include <stdio.h>
int main(){
    char c;
    scanf("%c",&c);
    switch(c){
        case 'a' ... 'z':
        case 'A' ... 'Z':
            printf("An Alphabet and ");
            if((c == 'a' || c == 'A') || (c == 'e' || c == 'E') || (c == 'i' || c == 'I') || (c == 'o' || c == 'O') || (c == 'u' || c == 'U')){
                printf("A Vowel");   
                break;             
            }
            else{
                printf("A consonant");
                break;
            }
        case 0 ... 9:
            printf("A digit");
            break;
        default:
            printf("A special character");
            
    }
}