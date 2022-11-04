/*write a menu driven program to perfom the following operations on a stack ADT using array
1. Push
2. Pop
3. Display
4. Sort
5. Add a element to the sorted stack
6. Find out the max element in stack*/
#include <stdio.h>
int stack[100],choice,n,top,x,i;
void push()
{
    if(top>=n-1)
    {
        printf("\nSTACK is over flow"); 
    }
    else
    {
        for(i=n; i>0; i--)
        {
        printf("\nEnter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
        }
    }
}
void pop(){
    if(top<=-1)
    {
        printf("\nStack is under flow");
    }
    else
    {
        printf("\nThe popped element is %d", stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\nThe elements in STACK \n");
        for(i=top; i>=0; i--)
        {
            printf("\n%d",stack[i]);
        }
        
    }
    else
    {
        printf("\nThe STACK is empty");
    }
   
}
int main()
{
    top=-1;
    printf("\nEnter the size of STACK:");
    scanf("%d",&n);
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
    do
    {
        printf("\nEnter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\nEXIT POINT ");
                break;
            }
            default:
            {
                printf ("\nPlease Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
