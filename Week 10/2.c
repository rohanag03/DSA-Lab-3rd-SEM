/*Write a menue driven programme to perform the following operations on a binary search-
i)create
ii)traverse in preorder
iii)traverse in inorder
iv)traverse in postorder
v)traverse in lelevorder
vi)search a given element
vii)deletion*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
};
struct node *create(struct node *root, int data)
{
    struct node *new, *node, *par;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->lptr = NULL;
    new->rptr = NULL;

    node = root;
    par = NULL;

    if (node == NULL)
    {
        root = new;
    }
    else
    {
        while (node != NULL)
        {
            par = node;
            if (data < node->data)
            {
                node = node->lptr;
            }
            else
            {
                node = node->rptr;
            }
        }
        if (data < par->data)
        {
            par->lptr = new;
        }
        else
        {
            par->rptr = new;
        }
    }
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->lptr);
        printf(" %d ", root->data);
        inorder(root->rptr);
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preorder(root->lptr);
        preorder(root->rptr);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->lptr);
        postorder(root->rptr);
        printf(" %d ", root->data);
    }
}
int height(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->lptr);
        int rheight = height(node->rptr);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
void printCurrentLevel(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printCurrentLevel(root->lptr, level - 1);
        printCurrentLevel(root->rptr, level - 1);
    }
}
void printLevelOrder(struct node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
struct node *search(struct node *node, int value)
{
    struct node *ptr;
    struct node *par;
    ptr = node;
    par = NULL;
    while (ptr->data != value)
    {
        par = ptr;
        if (value < ptr->data)
            ptr = ptr->lptr;
        else
            ptr = ptr->rptr;
    }
    if (ptr->data == value)
    {
        printf(" \nElement is present \n");
        printf("parent node is %d", par->data);
    }
    else
    {
        printf("\n Element not found\n");
    }
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    while (current != NULL && current->lptr != NULL)
        current = current->lptr;

    return current;
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
int main()
{
    int n, ch, d, e;
    struct node *root = NULL;
    printf("1.Create a BST\n");
    printf("2.Inorder traversal\n");
    printf("3.Preorder traversal\n");
    printf("4.Postorder traversal\n");
    printf("5.Levelorder traversal\n");
    printf("6.Search a node\n");
    printf("7.Delete a node\n");
    printf("8.Exit\n");
    while (1)
    {
        printf("Enter your choice!!\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data value :\n");
            scanf("%d", &n);
            root = create(root, n);
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            preorder(root);
            printf("\n");
            break;
        case 4:
            postorder(root);
            printf("\n");
            break;
        case 5:
            printLevelOrder(root);
            printf("\n");
            break;
        case 6:
            printf("enter the element to search\n");
            scanf("%d", &d);
            search(root, d);
            break;
        case 7:
            printf("enter the element to delete\n");
            scanf("%d", &e);
            deleteNode(root, e);
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Wrong choice. Try Again!!\n");
            continue;
        }
    }
    return 0;
}