#include <stdio.h>
#include <stdlib.h>

struct node{
   int info; 
   struct node *next;
};

struct node *create_new_node()
{
    struct node *ptr;
    ptr = (struct node *) malloc(sizeof(struct node));
    ptr->info = 0;
    ptr->next = NULL;
    return ptr;    
};

// insert a new node at first 
struct node *insert_first(struct node *start,int info)
{
    struct node *new_node;
    new_node = create_new_node();
   // printf("Enter data : ");
   // scanf("%d", &new_node->info);
    new_node->info = info;
    new_node->next = start;
    return new_node;
};

void display_list(struct node *start){
    struct node *temp = start;
    while(temp != NULL){
        printf("\nAddress = %p , info = %d , next address = %p",temp,temp->info,temp->next);
        temp = temp->next;
    }
}
// insert after a node
// display node - list traversal 

struct node *insert_after(struct node *start, int key, int info)
{
    struct node *temp = start;
    struct node *new_node = create_new_node();
    new_node->info = info;
    while(temp != NULL && temp->info != key)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("\nNode not found");
        return start;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return start;
}

struct node *delete_first(struct node *start)
{
    if(start == NULL)
    {
        printf("List is empty");
        return NULL;
    }
    start = start->next;
    return start;
}

struct node *delete_node(struct node *start, int val)
{
    struct node *temp = start;
    struct node *pre = start;

    while(temp != NULL)
    {
        if(temp->info == val)
        {   //To delete first, start will change
            if(temp == start){
                start = temp->next;
            }
            //Except first,till end
            else{
                pre->next = temp->next;
            } 
            return start;
        }
        pre = temp;
        temp = temp->next;
    }
    
    printf("\nNode not found.");
    return start;
}

struct node *nodemod(struct node *start, int old_info, int new_info)
{
    struct node *temp = start;
    while(temp != NULL)
    {
        if(temp->info == old_info)
        {
            temp->info = new_info;
            printf("\nNode modified! to %d",new_info);
            return start;
        }
        temp = temp->next;
    }
    printf("\nNode not found.");
    return start;
}
void search(struct node *start, int key)
{
    struct node *temp = start;
    while(temp != NULL)
    {
        if(temp->info == key)
        {
            printf("\nNode value '%d' found at address: %p", temp->info, temp);
            return;
        }
        temp = temp->next;
    }
    printf("\nNode value '%d' not found", key);
}
int main()
{   
    int val,key;
    int old_info, new_info;
    struct node *start = NULL;

    start = insert_first(start, 10);
    start = insert_first(start, 20);
    start = insert_first(start, 30);
    start = insert_first(start, 40);
    start = insert_first(start, 50);
   /* start = insert_first(start, 60);
    start = insert_first(start, 70);
    start = insert_first(start, 80);
    start = insert_first(start, 90);
    start = insert_first(start, 100);
    start = insert_first(start, 110);
    start = insert_first(start, 120);
    start = insert_first(start, 130);*/


    printf("Before deleting first node:\n");
    display_list(start);

    printf("\n Which node to delete after? : ");
    scanf("%d", &val);
    start = delete_node(start, val);

    printf("\nAfter deleting %dth node:\n", val);
    display_list(start);

    printf("\nWhich node to search? : ");
    scanf("%d", &key);
    search(start, key);

    printf("\nEnter the value to modify: ");
    scanf("%d", &old_info);
    printf("Enter the new value: ");
    scanf("%d", &new_info);
    start = nodemod(start, old_info, new_info);
    printf("\nAfter modification:\n");
    display_list(start);
}

