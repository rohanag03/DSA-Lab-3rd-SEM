#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
};

void create(struct node **root, int num)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n -> data = num;
    n -> lptr = NULL;
    n -> rptr = NULL;
    struct node *temp = (*root), *par = NULL;
    if(*root == NULL)
        *root = n;
    else
    {
        while(temp != NULL)
        {
            par = temp;
            if(num < temp -> data)
                temp = temp -> lptr;
            else
                temp = temp -> rptr;
        }
        if(num < par -> data)
            par -> lptr = n;
        else
            par -> rptr = n;
    }
}
void in(struct node **root)
{
    if((*root) == NULL)
        return;
    struct node *temp = (*root);
    in(&temp -> lptr);
    printf("%d\t", temp -> data);
    in(&temp -> rptr);
}
void pre(struct node **root)
{
    if((*root) == NULL)
        return;
    struct node *temp = (*root);
    printf("%d\t", temp -> data);
    pre(&temp -> lptr);
    pre(&temp -> rptr);
}
void post(struct node **root)
{
    if(*root == NULL)
        return;
    struct node *temp = (*root);
    post(&temp -> lptr);
    post(&temp -> rptr);
    printf("%d\t", temp -> data);
}
int heightoftree(struct node *root)
{
    int max;
    if (root!=NULL)
    {

        int leftsubtree = heightoftree(root->lptr);
        int rightsubtree = heightoftree(root->rptr);
        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            max = rightsubtree + 1;
            return max;
        }
    }
}
void levelor(struct node *root, int level)
{
    if (root != NULL) 
    {
        if (level == 1)
        {
            printf("%d ", root->data);
        }
        else if (level > 1) 
        { 
            levelor(root->lptr, level-1); 
            levelor(root->rptr, level-1);
        }			
    }
}
struct node *search(struct node *node, int value)
{
    struct node *ptr;
    struct node *par;
    ptr = node;
    par = NULL;
    while(ptr->data != value)
    {
        par = ptr;
        if(value<ptr->data)
            ptr = ptr->lptr;
        else
        ptr = ptr->rptr;
    }
    if(ptr->data == value)
    {
        printf(" \nElement is present \n");
        printf("Parent node is %d", par->data);
    }
    else
    {
        printf("\n Element not found\n");
    }
}
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->lptr = deleteNode(root->lptr, key);
    else if (key > root->data)
        root->rptr = deleteNode(root->rptr, key);
    else
    {
        if (root->lptr == NULL)
        {
            struct node *temp = root->rptr;
            free(root);
            return temp;
        }
        else if (root->rptr == NULL)
        {
            struct node *temp = root->lptr;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->rptr);
        root->data = temp->data;
        root->rptr = deleteNode(root->rptr, temp->data);
    }
    return root;
}
void main()
{
    struct node *root = NULL;
    int n = 1, ch, height, d,e;
    while(n == 1)
    {
        printf("\nMenu:\n");
        printf("1. Add numbers\n");
        printf("2. Preorder traverse\n");
        printf("3. Inorder traverse\n");
        printf("4. Postorder traverse\n");
        printf("5. Level Order traverse\n");
        printf("6. Search\n");
        printf("6. Search\n");
        printf("8. Delete\n");
        printf("Enter your choice: \n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                int num;
                printf("Enter number to be inserted: ");
                scanf("%d", &num);
                create(&root, num);
                break;
            }
            case 2: 
                pre(&root); 
                break;
            case 3: 
                in(&root); 
                break;
            case 4: 
                post(&root);
                break;
            case 5: 
                height = heightoftree(root);
                for(int i = 1; i <= height; i++)    
                {
                    levelor(root,i);
                }                      
                break;
            case 6: 
                printf("Enter the element to search:\n");
                scanf("%d", &d);
                search(root, d);
            break;

            case 7: 
                printf("enter the element to delete\n");
                scanf("%d", &e);
                deleteNode(root, e);
            break;

            case 8:
                exit(0);
        }
    }
}