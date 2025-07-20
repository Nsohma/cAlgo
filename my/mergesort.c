#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

void mergesortt(int i, int j, int *A);
void merge(int *A, int nA, int *B, int nB, int i, int *C);

int main(void){
    int A[N];
    for (int i=0; i<10; i++) A[i]=10-i;
    for (int i=0; i<10; i++) printf("A[%d]:%d ", i, A[i]);
    puts("");
    mergesortt(0, 9, A);
    for (int i=0; i<10; i++) printf("A[%d]:%d ", i, A[i]);
    puts("");
    return 0;
}

void mergesortt(int i, int j, int *A){
    // sort for A[i] ... A[j]
    int B[N], C[N];
    int mi = (i+j) / 2;
    if (j <= i) return;
    
    mergesortt(i, mi, A);
    mergesortt(mi+1, j, A);
    for (int l=i; l<mi+1; l++){
        B[l-i] = A[l];
    }
    for (int k=mi+1; k<j+1; k++) {
        C[k-mi-1] = A[k];
    }
    merge(B, mi-i+1, C, j-mi, i, A);
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
