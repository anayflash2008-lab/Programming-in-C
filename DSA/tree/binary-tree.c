#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *lptr; // left pointer
    struct node *rptr; // right pointer
};

struct node *create_new_node(int val)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->info = val;
    ptr->lptr = NULL;
    ptr->rptr = NULL;
    return ptr;
};
