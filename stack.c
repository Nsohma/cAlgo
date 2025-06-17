#include <stdio.h>

typedef struct{
    int element;
    cell *next;
} cell;

cell *push(int x, cell *init);
cell *pop(cell *init);

int main(void){
    return 0;
}

cell *push(int x, cell *init){
    cell *memo, *new;
    new = (cell *)malloc(sizeof(cell));
    memo = init;
    while (memo->next != NULL){ //find the last stack
        memo = memo->next;
    }
    new -> element =  x; new -> next = NULL; //create new stack
    memo -> next = new;
    return init;
}

cell *pop(cell *init){
    cell *memo, *prev;
    memo = init;
    if (init -> next == NULL){ //Error
        puts("Error : stack has no element");
        exit(1);
    }
    while (memo -> next != NULL){ //find the last stack
        prev = memo;
        memo = memo -> next;
    }
    prev -> next = NULL;
    free(memo);
    return init;
}
