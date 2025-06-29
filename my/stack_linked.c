#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
    int element;
    struct cell *next;
} cell;

cell *push(int x, cell *init);
cell *pop(cell *init);

int main(void){
    cell *init = (cell *)malloc(sizeof(cell));
    init -> next = NULL;
    push(3, init);
    push(4, init);
    push(5, init);
    push(6, init);
    pop(init);
    pop(init);
    while (init -> next != NULL){
        init = init -> next;
        printf("%d\n", init->element);
    }
    return 0;
}

cell *push(int x, cell *init){
    cell *new;
    new = (cell *)malloc(sizeof(cell));
    new -> element =  x; 
    new -> next = init -> next; //create new stack
    init -> next = new;
    return init;
}

//deep copy
//cell *push(int x, cell *init){
//    cell *q, *r;
//    r=(cell *)malloc(sizeof(cell));
//    q=init;                 
//    init=r;
//    r->element=x; r->next=q;
//    return(init);
//}

cell *pop(cell *init){
    cell *memo;
    memo = init->next;
    if (init -> next == NULL){ //Error
        puts("Error : stack has no element");
        exit(1);
    }
    init->next = memo->next;
    free(memo);
    return init;
}

//struct cell *pop(struct cell *init){ //deep copy
//    /*To use this function, you should make main function 
//    such as init = pop(init) to receive new init pointer*/
//    struct cell *q;
//    if(init!=NULL) {
//    q=init; init=init->next; free(q); return(init);
//    }
//    else {printf("Error: Stack is empty.\n"); exit(1);}
//}

