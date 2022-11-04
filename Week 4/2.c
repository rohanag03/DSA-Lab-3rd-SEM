//add nodde at begining
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *start = NULL;
void createList()
{
    int n;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    if (n != 0)
    {
        int ch;
        struct node *newnode;
        struct node *temp;
        newnode = (struct node *)malloc(sizeof(struct node));
        start = newnode;
        temp = start;
        printf("\nEnter number to be inserted : ");
        scanf("%d", &ch);
        start->data = ch;
        for (int i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            temp->next = newnode;
            printf("\nEnter number to be inserted : ");
            scanf("%d", &ch);
            newnode->data = ch;
            newnode->next = NULL;
            temp = temp->next;
        }
    }
    printf("\nThe list is created\n");
}
void insert(){
    struct node *n;
    struct node *t;
    struct node *n=(struct node *)malloc(sizeof (struct node));
    n->next=start;
    start=n;
}
int main()
{

}