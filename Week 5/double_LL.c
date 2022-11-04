#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
} * start, *last;
void createList(int n);
void first();
void end();

int main()
{
    int n, ch;
    start = NULL;
    last = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\n1. Display list from First");
    printf("\n2. Display list from End\n");
    printf("3. Exit.\n");
    scanf("%d", &ch);
    while (1)
    {
        if (ch == 1)
        {
            first();
        }
        else if (ch == 2)
        {
            end();
        }
        else if (ch == 3)
        {
            exit(0);
        }
        printf("\n1. Display list from First");
        printf("\n2. Display list from End\n");
        printf("3. Exit.\n");
        scanf("%d", &ch);
    }
    return 0;
}
void createList(int n)
{
    int i, data;
    struct node *newNode;
    if (n >= 1)
    {
        start = (struct node *)malloc(sizeof(struct node));
        if (start != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);
            start->data = data;
            start->prev = NULL;
            start->next = NULL;
            last = start;
            for (i = 2; i <= n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                if (newNode != NULL)
                {
                    printf("Enter data of node %d: ", i);
                    scanf("%d", &data);
                    newNode->data = data;
                    newNode->prev = last;
                    newNode->next = NULL;
                    last->next = newNode;
                    last = newNode;
                }
                else
                {
                    printf("Memory cannot be allocated.");
                    break;
                }
            }
            printf("\nDouble linked list created\n");
        }
        else
        {
            printf("Memory cannot be allocated.");
        }
    }
}
void first()
{
    struct node *temp;
    int n = 1;
    if (start == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = start;
        printf("\n\nData in List:\n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            n++;
            temp = temp->next;
        }
    }
}
void end()
{
    struct node *temp;
    int n = 0;
    if (last == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = last;
        printf("\n\nData in List:\n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            n++;
            temp = temp->prev;
        }
    }
}