#include <stdio.h>
#include <stdlib.h>

#define N 100
#define m 8
#define K 3

typedef struct {
    int letter[K];
} word;

typedef struct cell{
    int index; 
    struct cell *next;
} cell;

void bucketsort(word *A, int *idx, int n, int k);
void insert(word *A, int idx, cell **B, int k);
void radixsort(word *A, int *idx ,int n, int k);

int main(void){
    word A[N];
    int idx[N];

    return 0;
}

void bucketsort(word *A, int *idx, int n, int k){
    // adapt bucketsort to A[0], A[1], ... ,A[n-1] by k digits
    cell *B[m] = (cell *)malloc(sizeof(cell)); 
    A->letter[k];
    


    return;
}

void insert(word *A, int idx, cell **B, int k){
    //insert idx into backet B of A[idx].letter[k]
}

void radixsort(word *A, int *idx ,int n, int k){

    return;
}

