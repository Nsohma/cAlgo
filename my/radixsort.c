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
void insert(word *A, int idx, cell **backet, int k);
void radixsortt(word *A, int *idx ,int n);

int main(void){
    word A[N];
    int idx[N];
    for (int i=0; i<10; i++){
        for (int j=0; j<K; j++){
            A[i].letter[j] = (i*j + i+j + i%2) % m;
        }
    }
    for (int i=0; i<10; i++){
        for (int j=0; j<K; j++){
            printf("A[i].letter[j] : %d ", A[i].letter[j]);
        }
        puts("");
    }
    for (int i=0; i<10; i++) idx[i] = i;
    radixsortt(A, idx, 10);
    puts("--- radixsort ---");
    for (int i=0; i<10; i++){
        for (int j=0; j<K; j++){
            printf("A[i].letter[j] : %d ", A[idx[i]].letter[j]);
        }
        puts("");
    }
    return 0;
}

void bucketsort(word *A, int *idx, int n, int k){
    // adapt bucketsort to A[0], A[1], ... ,A[n-1] by k digits
    cell *backet[m];
    cell *new, *now;
    for (int i=0; i<m; i++){ //initialize backet
        backet[i] = NULL;
    }
    int memo=n-1;
    for (int j=0; j<n; j++){ // insert idx[j] to backet from j=0 ~ m-1
        insert(A, idx[j], backet, k);
    }
    for (int j=m-1; j>-1; j--){
        if (backet[j] != NULL){
            now = backet[j]->next;
            while (now != NULL){ // update idx[j] 
                idx[memo--] = now -> index;
                now = now -> next;
            }
        }
    }
    return;
}

void insert(word *A, int idx, cell **backet, int k){
    //insert idx into backet B of A[idx].letter[k]
    cell *new, *memo;
    new = (cell *)malloc(sizeof(cell));
    new -> index = idx; // make new cell
    if (backet[A[idx].letter[k]] != NULL){ //connect backet
        memo = backet[A[idx].letter[k]] -> next;
        new -> next = memo; 
        backet[A[idx].letter[k]] -> next = new;
    }
    else{
        backet[A[idx].letter[k]] = (cell *)malloc(sizeof(cell));
        new -> next = NULL;
        backet[A[idx].letter[k]] -> next = new;
    }
}

void radixsortt(word *A, int *idx ,int n){
    for (int k=K-1; k>-1; k--){ // radixsort for k digits
        bucketsort(A, idx, n, k);
    }
    return;
}

