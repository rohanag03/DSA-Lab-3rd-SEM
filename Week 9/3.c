//WAP to implement circular roatation of an array using dequeue.
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

struct Queue {
    int q[MAX_SIZE];
    int f, r;
};

void init(struct Queue **q ){
    *q = (struct Queue*)malloc( sizeof( struct Queue ) );
    (*q)->f = -1;
    (*q)->r = -1;
}

void insert( struct Queue *q, int value, int choice ){
    if( (q->f == -1 && q->r == MAX_SIZE-1 ) || q->f == (q->r%MAX_SIZE)+1 ){
        printf("Overflow!\n");
        return;
    }
    if( choice )
        q->q[(++(q->r))%MAX_SIZE] = value;
    else
        q->q[(q->f)--] = value;
    
}

void delete( struct Queue *q, int *b ){
    if( q->f == q->r ){
        printf("Underflow.\n");
        q->f = -1;
        q->r = -1;
        return;
    }
    *b = q->q[(++(q->f))%MAX_SIZE];
    if( q->f == q->r ){
        q->f = -1;
        q->r = -1;
    }
}

int read( struct Queue *q, int choice ){
    if( choice )
        return q->q[((q->f)+1)%MAX_SIZE];
    else
        return q->q[(q->r)%MAX_SIZE];
}

int main(){

    struct Queue *q = NULL;
    init( &q );
    insert( q, 10, 1 );
    insert( q, 20, 1 );
    insert( q, 30, 1 );
    for( int i = 0; i < MAX_SIZE; i++ )
        printf("%d ", q->q[i]);
    printf("\n");

    int b;
    delete( q, &b );
    printf("Deleted: %d\n", b);
    
    insert( q, 40, 0 );

    for( int i = 0; i < MAX_SIZE; i++ )
        printf("%d ", q->q[i]);
    printf("\n");
    return 0;
}