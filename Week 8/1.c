//Implement a circular queue by writing a menu driven prgram with functions like insertion, deletion adn display
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int arr[MAX];
int front=-1;
int rear=-1;

int empty()
{
        if(front==-1)
                return 1;
        else
                return 0;
}

int full()
{
        if((front==0 && rear==MAX-1) || (front==rear+1))
                return 1;
        else
                return 0;
}

void insert(int item)
{
        if( full() )
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if(front == -1 )
                front=0;

        if(rear==MAX-1)
                rear=0;
        else
                rear=rear+1;
        arr[rear]=item ;
}

int del()
{
        int item;
        if( empty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        item=arr[front];
        if(front==rear) 
        {
                front=-1;
                rear=-1;
        }
        else if(front==MAX-1)
                front=0;
        else
                front=front+1;
        return item;
}

void display()
{
        int i;
        if(empty())
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue elements :\n");
        i=front;
        if( front<=rear )
        {
                while(i<=rear)
                        printf("%d ",arr[i++]);
        }
        else
        {
                while(i<=MAX-1)
                        printf("%d ",arr[i++]);
                i=0;
                while(i<=rear)
                        printf("%d ",arr[i++]);
        }
        printf("\n");
}

int main()
{
        int choice,item;
        while(1)
        {
                printf("\n1.Insert\n");
                printf("2.Delete\n");
                printf("3.Display\n");
                printf("4.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                case 1 :
                        printf("\nInput the element for insertion: ");
                        scanf("%d",&item);
                        insert(item);
                        break;
                case 2 :
                        printf("\nElement deleted is: %d\n",del());
                        break;
                case 3:
                        display();
                        break;
                case 4:
                        exit(1);
                default:
                        printf("\nWrong choice\n");
                }
        }

        return 0;

}