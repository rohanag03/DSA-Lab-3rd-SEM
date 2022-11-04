#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

#define CAPACITY 10000  
struct stack 
{
    int data;
    struct stack *next;
} *top;

int size = 0;

void push(int element);
int  pop();
void display();


int main()
{
    int ch, data;

    while(1)
    {
    
        printf("\nEnter task you want to perform : \n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d", &ch);

        switch(ch) 
        {
            case 1: 
                printf("\nEnter data to push:  ");
                scanf("%d", &data);
                push(data);
                break;

            case 2: 
                data = pop();
                if (data != INT_MIN)
                    printf("Data => %d\n", data);
                break;
            case 3: 
                display();
                break;

            case 4: 
                exit(0);
                break;

            default: 
                printf("Invalid \n");
        }
    }
    return 0;
}

void push(int element)
{
    
    if (size >= CAPACITY)
    {
        printf("Stack Overflow\n");
        return;
    }
    struct stack * newNode = (struct stack *) malloc(sizeof(struct stack));
    newNode->data = element;
    newNode->next = top;        
    top = newNode;
    size++;
}

int pop()
{
    int data = 0;
    struct stack * topNode;
    
    if (size <= 0 || !top)
    {
        printf("EMPTY STACK \n");

        
        return INT_MIN;
    }
    topNode = top;
    data = top->data;
    top = top->next;
    free(topNode); 
    size--;
    return data;
}

void display()
{
   if(top == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct stack *temp = top;
      while(temp->next != NULL){
	 printf("%d\t",temp->data);
	 temp = temp -> next;
      }
      printf("%d",temp->data);
   }
}