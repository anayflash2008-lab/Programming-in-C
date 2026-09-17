/*A security access terminal requires an employee to swipe a smartcard that emits a single ASCII character token. The terminal rules state:
If the token is an alphabetic character ('A'–'Z' or 'a'–'z'), access is granted to office areas. 
If the token is a numeric digit ('0'–'9'), access is granted to warehouse zones. 
If the token is any other printable character (special symbol), access is denied, and a security alert is logged. 
Questions:
Write a C program snippet using compound Boolean expressions (&&, ||) inside an if...else if...else structure to classify the input token without using external library functions. 
Modify your validation logic to identify whether an alphabetic token is a vowel or a consonant
*/
#include <stdio.h>

int main()
{
    char c;
    printf("Enter token: ");
    scanf("%c", &c);
    // A to Z
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        printf("Office access granted\n");
        // Vowel condition
        if (c == 'A' || c == 'E' || c == 'I' ||c == 'O' || c == 'U' ||c == 'a' || 
            c == 'e' || c == 'i' ||c == 'o' || c == 'u')
        {
            printf("It is a vowel");
        }
        else
        {
            printf("It is a consonant");
        }
    }
    // Digit
    else if (c >= '0' && c <= '9')
    {
        printf("Warehouse access granted");
    }
    // Special characters as else
    else
    {
        printf("Access denied\n");
        printf("Security alert logged");
    }
}