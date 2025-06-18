#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct{
    int top;
    int element[N];
} stack;

void push(int x, stack *S);
int pop(stack *S);

int main(void){
    stack *S;
    S = (stack *)malloc(sizeof(stack));
    S -> top = N; // because top element is null
    
    for (int i=0; i<10; i++){
        push(i, S);
    }
    for (int i=0; i<10; i++){
        printf("element[%d] : %d\n", (S->top)+i, S->element[(S->top)+i]);
    }
    for (int i=0; i<3; i++){
        printf("pop value : %d \n", pop(S));
    }
    for (int i=0; i<10; i++){
        if ((S->top)+i < N) printf("element[%d] : %d\n", (S->top)+i, S->element[(S->top)+i]);
    }
    return 0;
}

void push(int x, stack *S){
    S->element[S->top - 1] = x;
    (S->top)--;
}

int pop(stack *S){
    int ret = S->element[S->top];
    S->element[S->top] = NULL;
    (S->top)++;
    return ret;
}

