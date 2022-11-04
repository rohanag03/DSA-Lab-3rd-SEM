#include<stdio.h>
struct stack{
int arr[100];
int top;
};
void initialise(struct stack* s){
s->top= -1;
}
void push(struct stack*s, int n){
if (s->top==99){
printf("Stack overflow\n");
return;
}
s->arr[++s->top]= n;
}
int pop(struct stack* s){
if (s->top==-1){
printf("Stack underflow\n");
return -1;
}
int x;
x= s->arr[s->top--];
return x;
}
void display(struct stack s){
while (s.top)
printf("%d ",s.arr[s.top--]);
printf("\n");
}
void sorted_insert(struct stack *s, int n){
if (s->top==-1 || s->arr[s->top]<n){
push(s,n);
return;
}
int b= pop(s);
sorted_insert(s,n);
push(s,b);
}
void sort(struct stack *s){
if (s->top==-1)
return;
int b= pop(s);
sort(s);
sorted_insert(s,b);
}
void main(){
struct stack a;
initialise(&a);
int c=1, n;
while (c!=0){
printf("1: Push\n2: Pop\n3: Display\n4: Sort\n5: Sorted insert\n6: Find max\n>");
scanf("%d",&c);   
switch(c){
case 0:
break;
case 1:
printf("Enter value: ");
scanf("%d", &n);
push(&a, n);
break;
case 2:
pop(&a);
break;
case 3:
display(a);
break;
case 4:
sort(&a);
break;
case 5:
printf("Enter value: ");
scanf("%d", &n);
sorted_insert(&a, n);
default:
printf("Invalid\n");
break;
}
}
}