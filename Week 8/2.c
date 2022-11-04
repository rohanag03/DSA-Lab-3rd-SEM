//Implement a queue ADT
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void insert();
void delete();
void display();
int arr[MAX];
int rear = - 1;
int front = - 1;

void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("Inset the element: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        arr[rear] = add_item;
    }
}
 
void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow\n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is: %d\n", arr[front]);
        front = front + 1;
    }
}
 
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is: \n");
        for (i = front; i <= rear; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        }
    }
}