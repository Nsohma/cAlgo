#include <stdio.h>
#include <stdlib.h>

#define N 100

void merge(int *A, int nA, int *B, int nB, int i, int *C);

int main(void){
    int A[N], B[N], C[N];
    for (int i=0; i<10; i++) A[i] = i;
    for (int i=0; i<5; i++) B[i] = 3*i;
    for (int i=0; i<10; i++) printf("A[%d]:%d ", i, A[i]);
    puts("");
    for (int i=0; i<5; i++) printf("B[%d]:%d ", i, B[i]);
    puts("");
    merge(A, 10, B, 5, 0, C);
    for (int i=0; i<15; i++) printf("C[%d]:%d ", i, C[i]);
    return 0;
}

void merge(int *A, int nA, int *B, int nB, int i, int *C){
    //merge A[0] ... A[nA-1] and B[0] ... B[nB-1]
    //put C[i] ... C[i+nA+nB-1]
    int a=0, b=0, c=i;
    while (a < nA && b < nB){
        if (A[a] > B[b]){
            C[c] = B[b];
            b++;
        }
        else{
            C[c] = A[a];
            a++; 
        }
        c++;
    }
    if (a < nA){
        for (int j=a; j<nA; j++){
            C[c++] = A[j];
        }
    }
    else if (b < nB){
        for (int j=b; j<nB; j++){
            C[c++] = B[j];
        }  
    }
}

