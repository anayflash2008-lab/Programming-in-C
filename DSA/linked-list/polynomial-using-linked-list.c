#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node *createNode(int coeff, int exp)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}
int main()
{
    struct Node *head;
    head = createNode(5, 4);
    printf("Coefficient = %d\n", head->coeff);
    printf("Exponent = %d\n", head->exp);
}