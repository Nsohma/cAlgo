#include <stdio.h>
#include <stdlib.h>

#define N 100

void heapsortt(int *A, int n);
void heapify(int *A, int n);
void downmax(int i, int *A, int n);
int deletemax(int *A, int k);
void swap(int i, int j, int *A);

int main(void){
    int A[N];
    for (int i=0; i<10; i++) A[i] = 10 - i;
    for (int i=0; i<10; i++) printf("A[%d]: %d ", i, A[i]);
    heapsortt(A, 10);
    puts("");
    for (int i=0; i<10; i++) printf("A[%d]: %d ", i, A[i]);
    puts("");
    return 0;
}

void heapsortt(int *A, int n){
    int i;
    heapify(A, n);
    for (int i=n-1; i>-1; i--) A[i] = deletemax(A, i+1);
}

void heapify(int *A, int n){
    for (int i=n/2-1; i>=0; i--) downmax(i, A, n);
}

void downmax(int i, int *A, int n){
    if (2*i+1 >= n) return;
    else if (A[i] >= A[2*i+1] && A[i] >= A[2*i+2]) return;
    if (A[2*i+1] > A[2*i+2]){
        swap(i, 2*i+1, A);
        downmax(2*i+1, A, n);
    }
    else{
        swap(i, 2*i+2, A);
        downmax(2*i+2, A, n);
    }
}

int deletemax(int *A, int k){
    int ret = A[0];
    A[0] = A[k-1];
    downmax(0, A, k-1);
    return ret;
}

void swap(int i, int j, int *A){
    int temp; 
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
