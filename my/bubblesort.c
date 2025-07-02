#include <stdio.h>
#include <stdlib.h>

void bubblesort(int h, int k, int *A);
void swap(int i, int j, int *A);

int main(void){
    int A[] = {5, 4, 3, 2, 1};
    int B[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubblesort(0, 4, A);
    for (int i=0; i<5; i++) printf("%d ", A[i]);
    bubblesort(0, 9, B);
    puts("");
    for (int i=0; i<10; i++) printf("%d ", B[i]);
    return 0;
}

void bubblesort(int h, int k, int *A){
    for (int i=0; i<k-h; i++){
        for (int j=k-1; j > h-1+i; j--){
            if (A[j] > A[j+1]) swap(j, j+1, A);
        }
    }
}

void swap(int i, int j, int *A){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}


