#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *create_new_node(int info)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = info;
    newnode->lptr = NULL;
    newnode->rptr = NULL;
    return newnode;
}

// InOrder Traversal
struct node *searchnode(struct node *root, int keyinfo)
{
    if (root == NULL)
        return NULL;
    if (root->info == keyinfo)
        return root;
    struct node *temp = searchnode(root->lptr, keyinfo);
    if (temp != NULL)
        return temp;
    else
        return searchnode(root->rptr, keyinfo);
}

struct node *insert(struct node *root, int info, int keyinfo, int insloc)
{
    struct node *ptr_curnode;
    struct node *temp;
    struct node *newnode = create_new_node(info);
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        ptr_curnode = searchnode(root, keyinfo);
        if (ptr_curnode == NULL)
        {
            printf("node not found, therefore cannot insert");
        }
        else
        {
            // Insert to the left
            if (insloc == 0)
            { 
                temp = ptr_curnode->lptr;
                ptr_curnode->lptr = newnode;
                newnode->lptr = temp;
            }
            // insert to the right
            else
            { 
                temp = ptr_curnode->rptr;
                ptr_curnode->rptr = newnode;
                newnode->rptr = temp;
            }
        }
    }
    return root;
}
void preorder(struct node *root){
    if (root == NULL)
        return;
    printf("address = 0x%x, lptr = 0x%x info = %d rptr = 0x%x\n",root,root->lptr, root->info, root->rptr);
    inorder(root->lptr);
    inorder(root->rptr);
}
void inorder(struct node *root){
    if (root == NULL)
        return;
    inorder(root->lptr);
    printf("address = 0x%x, lptr = 0x%x info = %d rptr = 0x%x\n",root,root->lptr, root->info, root->rptr);
    inorder(root->rptr);
}

void postorder(struct node *root){
    if (root == NULL)
        return;
    inorder(root->lptr);
    inorder(root->rptr);
    printf("address = 0x%x, lptr = 0x%x info = %d rptr = 0x%x\n",root,root->lptr, root->info, root->rptr);
}
void traversal(struct node *root, int type)
{
    if (root == NULL)
        return;
    if (type == 1)
        printf("%d -> ", root->info);
    traversal(root->lptr, type);
    if (type == 2)
        printf("%d -> ", root->info);
    traversal(root->rptr, type);
    if (type == 3)
        printf("%d -> ", root->info);
}
int main()
{
    struct node *root = NULL;
    root = insert(root,10,0,0);
    insert(root,20,10,0);
    insert(root,30,10,1);
    insert(root,40,30,1);
    printf("Preorder:  ");
    traversal(root, 1);
    printf("NULL\n");

    printf("Inorder:   ");
    traversal(root, 2);
    printf("NULL\n");

    printf("Postorder: ");
    traversal(root, 3);
    printf("NULL\n");

}