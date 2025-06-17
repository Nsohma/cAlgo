#include <stdio.h>
#include <stdlib.h>

typedef struct{ //cell definition
    int element;
    struct cell *next;
} cell;

cell* insert(int x, cell *p, cell *init);
cell* delete(cell *p, cell *init);

int main(void){
    cell *a;
    a = (cell*)malloc(sizeof(cell*));
    a -> element = 1;
    

    return 0;
}

cell *insert(int x, cell *p, cell *init){
    //if p == NULL , *init.element = x
    //if p != NULL , *p.element = x 
    cell *new, *memo;
    new = (cell*)malloc(sizeof(cell*)); //dynamic memolly allocation and initialize
    new -> element = x;
    if (p == NULL){
        new -> next = init -> next;
        init -> next = new;
    }
    else{
        new -> next = p -> next;
        p -> next = new;
    }
    return init;
}


