#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 500

int deletemin(int *A, int *n);
void downmin(int i, int *A, int n);
void swap(int i, int j, int *A);
void insert(int x, int *A, int *n);
void upmin(int i, int *A, int n);

int main(void){
    //realize heap by use array
    //if A[i] is parent -> children = A[2i+1] and A[2i+2]
    //left child = A[2i+1] and right child = A[2i+2]
    int A[N];
    int n, i, k, min;
    n=0;
    for(k=0; k<10; k++) {
        insert(100-(5-i)*(5-i), A, &n);
        printf("n = %d\nA = ", n);
        for(i=0; i<n; i++) printf("%d ",A[i]);
        printf("\n");
    }

    for(k=0; k<10; k++) {
        min=deletemin(A, &n);
        printf("n = %d, min = %d\nA = ", n, min);
        for(i=0; i<n; i++) printf("%d ",A[i]);
        printf("\n");
    }
    return 0;
}

int deletemin(int *A, int *n){
    //delete and output min A[0] from heap (A[0] ... A[n-1])
    int min = A[0];
    (*n)--;
    A[0] = A[*n];
    downmin(0, A, *n);
    return min;
}
void insert(int x, int *A, int *n){
    //insert x to heap A
    A[*n] = x;
    (*n)++;
    upmin(*n-1, A, *n);
}

void downmin(int i, int *A, int n){
    //adapt swap to A which is under from i 
    //and recovery heap
    int min = 2*i+1;// left child
    if (min >= n) return; // distinguish A child exist
    if (min + 1 < n && A[min] > A[min+1]) min++;
    if (A[min] >= A[i]) return;

    swap(i, min, A);
    downmin(min, A, n);
}


void upmin(int i, int *A, int n){
    //swap A which is upper from i
    //and recovery heap
    int parent = (int)floor((i-1)/2);
    if (A[i] >= A[parent]) return;

    swap(i, parent, A);
    upmin(parent, A, n);
}

void swap(int i, int j, int *A){
    //swap A[i] and A[j]
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

