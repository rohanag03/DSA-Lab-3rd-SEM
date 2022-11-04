//WAP to implement circular roatation of an array using dequeue. #include <stdio.h>
#include <stdlib.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
void ins_fr(int);
void ins_re(int);
void del_fr();
void del_re();
void display();
int main()
{
int ch, val;
while (1)
{
printf("\n\n1. Insert at front end\n2. Insert at rear end\n3. Delete from front end\n4. Delete from rear end\n5. Display\n6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
printf("Enter the value to be inserted: ");
scanf("%d", &val);
ins_fr(val);
break;
case 2:
printf("Enter the value to be inserted: ");
scanf("%d", &val);
ins_re(val);
break;
case 3:
del_fr();
break;
case 4:
del_re();
break;
case 5:
display();
break;
case 6:
exit(0);
default:
printf("Invalid choice");
}

}
return 0;
}
void ins_fr(int val)
{
if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
{
printf("Queue Overflow");
return;
}
if (front == -1)
{
front = 0;
rear = 0;
}
else
{
if (front == 0)
front = MAX - 1;
else
front = front - 1;
}
queue[front] = val;
}
void ins_re(int val)
{
if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
{
printf("Queue Overflow");
return;
}
if (front == -1)
{
front = 0;
rear = 0;
}
else
{
if (rear == MAX - 1)
rear = 0;
else
rear = rear + 1;
}
queue[rear] = val;
}
void del_fr()
{

if (front == -1)
{
printf("Queue Underflow");
return;
}
printf("Element deleted from queue is : %d", queue[front]);
if (front == rear)
{
front = -1;
rear = -1;
}
else
{
if (front == MAX - 1)
front = 0;
else
front = front + 1;
}
}
void del_re()
{
if (front == -1)
{
printf("Queue Underflow");
return;
}
printf("Element deleted from queue is : %d\n", queue[rear]);
if (front == rear)
{
front = -1;
rear = -1;
}
else
{
if (rear == 0)
rear = MAX - 1;
else
rear = rear - 1;
}
}
void display()
{
int front_pos = front, rear_pos = rear;
if (front == -1)
{
printf("Queue is empty");
return;

}
printf("Queue elements : ");
if (front_pos <= rear_pos)
while (front_pos <= rear_pos)
{
printf("%d ", queue[front_pos]);
front_pos++;
}
else
{
while (front_pos <= MAX - 1)
{
printf("%d ", queue[front_pos]);
front_pos++;
}
front_pos = 0;
while (front_pos <= rear_pos)
{
printf("%d ", queue[front_pos]);
front_pos++;
}
}
}