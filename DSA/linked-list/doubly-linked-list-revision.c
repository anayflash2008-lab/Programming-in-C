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
// insert new node at first
struct node insert_first(struct node *first_node,int info)
{
    struct node *new_node;
    new_node = create_new_node(info);
    if(first_node == NULL){
        first_node = new_node;
    }
    else{
        new_node->rptr = first_node;
        first_node->lptr = new_node;
        first_node = new_node;
    }
}
// insert new node at last
struct node insert_last(struct node *first_node, int info, struct node *last_node)
{
    struct node *new_node;
    new_node = create_new_node(info);
    if(last_node == NULL){
        last_node = new_node;
    }
    else{
        new_node->lptr = last_node;
        last_node->rptr = new_node;
        last_node = new_node;
    }
}
// insert new node after a node in between
struct node insert_after(struct node *first_node, int key, int val)
{
    
}