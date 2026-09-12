#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *create_new_node(int val)
{
    struct node *ptr;

    ptr = (struct node *)malloc(sizeof(struct node));

    ptr->info = val;
    ptr->lptr = NULL;
    ptr->rptr = NULL;

    return ptr;
}


// Insert at first
struct node *insert_first(struct node *first_node, int info)
{
    struct node *new_node;

    new_node = create_new_node(info);

    if(first_node == NULL)
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
}


// Insert at last
struct node *insert_last(struct node *first_node, int info)
{
    struct node *new_node;
    struct node *temp;

    new_node = create_new_node(info);

    if(first_node == NULL)
    {
        first_node = new_node;
    }
    else
    {
        temp = first_node;

        while(temp->rptr != NULL)
            temp = temp->rptr;

        temp->rptr = new_node;
        new_node->lptr = temp;
    }

    return first_node;
}


// Insert after a node
struct node *insert_after(struct node *first_node, int key, int val)
{
    struct node *temp = first_node;

    while(temp != NULL && temp->info != key)
        temp = temp->rptr;


    if(temp == NULL)
    {
        printf("Node not found\n");
        return first_node;
    }


    struct node *new_node = create_new_node(val);


    new_node->lptr = temp;
    new_node->rptr = temp->rptr;


    if(temp->rptr != NULL)
        temp->rptr->lptr = new_node;


    temp->rptr = new_node;


    return first_node;
}


// Modify node
void modify_node(struct node *first_node, int old_val, int new_val)
{
    struct node *temp = first_node;


    while(temp != NULL)
    {
        if(temp->info == old_val)
        {
            temp->info = new_val;
            printf("Node modified\n");
            return;
        }

        temp = temp->rptr;
    }


    printf("Node not found\n");
}


// Delete node
struct node *delete_node(struct node *first_node, int val)
{
    struct node *temp = first_node;


    while(temp != NULL && temp->info != val)
        temp = temp->rptr;


    if(temp == NULL)
    {
        printf("Node not found\n");
        return first_node;
    }


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


    free(temp);

    printf("Node deleted\n");

    return first_node;
}


// Display
void display_LL(struct node *first_node)
{
    struct node *temp = first_node;


    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }


    while(temp != NULL)
    {
        printf("%d <-> ", temp->info);
        temp = temp->rptr;
    }

    printf("NULL\n");
}

void savefile(int val)
{
    FILE *fp;
    fp = fopen("LinkedList.dat","ab+");
    fwrite(&val,sizeof(val),1,fp);
    fclose(fp);

}

struct node *createlistfromfile(struct node *fn)
{
    int val;
    FILE *fp;
    fp = fopen("LinkedList.dat","rb");
    while(!feof(fp))
    {
        fread(&val,sizeof(val),1,fp);
        fn = insert_first(fn,val);

    }
    fclose(fp);
    return fn;
    
}
int main()
{
    struct node *first_node = NULL;

    int ch;
    int val, key, new_val;

    while(1)
    {
        printf("\n----- DOUBLY LINKED LIST MENU -----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after node\n");
        printf("4. Modify node\n");
        printf("5. Delete node\n");
        printf("6. Display list\n");
        printf("7. Create from file\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&val);

                first_node = insert_first(first_node,val);
                savefile(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&val);

                first_node = insert_last(first_node,val);
                savefile(val);

                break;

            case 3:
                printf("Enter node after which to insert: ");
                scanf("%d",&key);

                printf("Enter value: ");
                scanf("%d",&val);

                first_node = insert_after(first_node,key,val);
                savefile(val);
                break;

            case 4:
                printf("Enter old value: ");
                scanf("%d",&val);

                printf("Enter new value: ");
                scanf("%d",&new_val);

                modify_node(first_node,val,new_val);
                break;

            case 5:
                printf("Enter value to delete: ");
                scanf("%d",&val);

                first_node = delete_node(first_node,val);
                break;

            case 6:
                display_LL(first_node);
                break;

            case 7:
                first_node = createlistfromfile(first_node);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }


    return 0;
}