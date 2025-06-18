#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
    int element;
    struct cell *next;
} cell;

typedef struct {
    cell *front;
    cell *rear;
} queue;

void enqueue(int x, queue *Q);
void dequeue(queue *Q);

int main(void){ 
    queue *Q;
    cell *prin;
    Q = (queue *)malloc(sizeof(queue));
    Q -> front = NULL; Q -> rear = NULL;
    for (int i=0; i<10; i++){
        enqueue(i, Q);
    }
    prin = Q->front;
    for (int i=0; i<10; i++){
        printf("p%p : %d\n", prin, prin->element);
        prin = prin -> next;
    }
    puts("");
    for (int i=0; i<3; i++){
        dequeue(Q);
    }
    prin = Q -> front;
    for (int i=0; i<7; i++){
        printf("p%p : %d\n", prin, prin->element);
        prin = prin -> next;
    }
    return 0;
}

void enqueue(int x, queue *Q){
    cell *new, *last;
    new = (cell *)malloc(sizeof(cell));
    new -> element = x; new -> next = NULL;
    if (Q->rear == NULL){
        Q ->front = new; Q ->rear = new;
    } else{
        (Q->rear) -> next = new;
        Q->rear = new;
    }
}

void dequeue(queue *Q){
    cell *top;
    top = Q->front;
    Q -> front = (Q->front) -> next;
    free(top);
}

