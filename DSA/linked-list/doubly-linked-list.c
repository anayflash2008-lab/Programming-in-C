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
struct node *insert_first(struct node *first_node, int info)
{
    struct node *new_node;
    new_node = create_new_node(info);
    if (first_node == NULL)
    {
        first_node = new_node;
    }
    else
    {
        new_node->rptr = first_node;
        first_node->lptr = new_node;
        first_node = new_node;
    }

    return first_node;
};

struct node *insert_last(struct node *first_node, int info, struct node *last_node)
{
    struct node *new_node;
    new_node = create_new_node(info);

    if (last_node == NULL)
    {
        last_node = new_node;
    }
    else
    {
        new_node->lptr = last_node;
        last_node->rptr = new_node;
        last_node = new_node;
    }
    return last_node;
};

// Insert after a given node
struct node *insert_after(struct node *first_node, int key, int val)
{
    struct node *temp = first_node;

    while (temp != NULL && temp->info != key)
        temp = temp->rptr;

    if (temp == NULL)
    {
        printf("Node not found!\n");
        return first_node;
    }

    struct node *new_node = create_new_node(val);

    new_node->lptr = temp;
    new_node->rptr = temp->rptr;

    if (temp->rptr != NULL)
        temp->rptr->lptr = new_node;

    temp->rptr = new_node;

    return first_node;
}

// Modify a node
void modify_node(struct node *first_node, int old_val, int new_val)
{
    struct node *temp = first_node;

    while(temp != NULL)
    {
        if(temp->info == old_val)
        {
            temp->info = new_val;
            return;
        }
        temp = temp->rptr;
    }

    printf("Node not found!\n");
}

// delete a node 
struct node *delete_node(struct node *first_node, int val)
{
    struct node *temp = first_node;

    while(temp != NULL && temp->info != val)
        temp = temp->rptr;

    if(temp == NULL)
    {
        printf("Node not found!\n");
        return first_node;
    }

    // deleting first node
    if(temp->lptr == NULL)
    {
        first_node = temp->rptr;

        if(first_node != NULL)
            first_node->lptr = NULL;
    }
    else
    {
        temp->lptr->rptr = temp->rptr;

        if(temp->rptr != NULL)
            temp->rptr->lptr = temp->lptr;
    }


    return first_node;
}

// searching a node
struct node *search_node(struct node *first_node, int val)
{
    struct node *temp = first_node;
    while(temp != NULL)
    {
        if(temp->info == val)
            break;

        temp = temp->rptr;
    }
    return temp;
}

// sorting nodes in ascending order
struct node *sort_node(struct node *first_node)
{
    
}

void display_LL(struct node *first_node)
{                       
    struct node *temp = first_node;
    while(temp != NULL){
        printf("node address -> %x, lptr -> %x, info = %d, rptr -> %x\n ",temp, temp->lptr,temp->info,temp->rptr);
        temp = temp->rptr;
    }
}

int main()
{
    struct node *first_node = NULL;
    struct node *last_node = NULL;
    struct node *found;

    first_node = insert_first(first_node,20);

    if(last_node == NULL)
        last_node = first_node;

    first_node = insert_first(first_node,10);

    last_node = insert_last(first_node,30,last_node);

    printf("Original List:\n");
    display_LL(first_node);

    first_node = insert_after(first_node,20,25);

    printf("\nAfter Inserting 25:\n");
    display_LL(first_node);

    modify_node(first_node,25,50);

    printf("\nAfter Modifying 25 to 50:\n");
    display_LL(first_node);

    first_node = delete_node(first_node,20);

    printf("\nAfter Deleting 20:\n");
    display_LL(first_node);

    printf("\n\n---------------------------------Searching---------------------------------");
    found = search_node(first_node, 50);    
    if(found){
        printf("\nNode containing Value %d is found\nAddress is %x\n",found->info,found);
    }
    else{
        printf("\nNode not found\n");
    }
}