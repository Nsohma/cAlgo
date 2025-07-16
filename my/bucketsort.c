#include <stdio.h>
#include <stdlib.h>

#define N 100
#define m 8
#define K 3

typedef struct cell{
    int element; 
    struct cell *next;
} cell;

void bucketsort(int *A, int n);
void insert(int *A, cell **backet, int n);

int main(void){
    int A[N];
    for (int i=0; i<10; i++){
        A[i] = (10-i)%m;
    }
    for (int i=0; i<10; i++) printf("A[%d]:%d  ", i, A[i]);
    puts("");
    bucketsort(A, 10);
    for (int i=0; i<10; i++) printf("A[%d]:%d  ", i, A[i]);
    puts("");

    return 0;
}

void bucketsort(int *A, int n){
    cell *backet[m];
    cell *new, *now;
    for (int i=0; i<m; i++){
        backet[i] = NULL;
    }
    int memo=n-1;
    insert(A, backet, n);
    for (int j=m-1; j>-1; j--){
        if (backet[j] != NULL){
            now = backet[j]->next;
            while (now != NULL){
                A[memo] = now -> element;
                memo--;
                now = now -> next;
            }
        }
    }
}

void insert(int *A, cell **backet, int n){
    cell *new, *memo;
    for (int i=0; i<n; i++){ 
        new = (cell *)malloc(sizeof(cell));
        new -> element = A[i]; 
        if (backet[A[i]] != NULL){
            memo = backet[A[i]] -> next;
            new -> next = memo;
            backet[A[i]]->next = new;
        }
        else{
            backet[A[i]] = (cell *)malloc(sizeof(cell));
            new -> next = NULL;
            backet[A[i]] -> next = new;
        }
    }
}

