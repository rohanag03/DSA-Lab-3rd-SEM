#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
} *root, *parent, *node;
void create ()
{
    struct node *new, *parent, *temp;
    int n;
    printf("Enter the number of nodes you want to create:");
    scanf("%d", &n);
    int ch;
    if(n!=0)
    {
        printf("Enter the value to be inserted");
        scanf("%d", &ch);
        if(root= NULL)
        {
         new = (struct node *)malloc(sizeof(struct node));
         root=new;
         temp=root;
         root->lptr=NULL;
         root->rptr=NULL;
         root->data=ch;
        }
        else
        {
            parent=node;
            while(root!=NULL)
            {
                parent=root;
                if(ch<root->data)
                    node=root->lptr;
                else
                    root=root->rptr;
            }
            if(ch<parent->data)
                parent->lptr=new;
            else
                parent->rptr=new;
        }
    }   
}
void inorder()
{
    if(root!=NULL)
    {
        inorder(node->lptr);
        printf("%d", node->data);
        inorder(node->rptr);
    }
}

int main()
{
    int choice, p=1;
    printf("\n\n 1. Create\n 2. Inorder\n\n");
    scanf("%d", &choice);
    while(p==1)
    {
        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                inorder();
                break;
        }
    printf("\n\n 1. Create\n 2. Inorder\n\n");
    scanf("%d", &choice);
    }
return 0;
}



void post(struct node **root)
{
    if(*root == NULL)
        return;
    struct node *temp = (*root);
    pre(&temp -> lptr);
    pre(&temp -> rptr);
    printf("%d\t", temp -> data);
}
