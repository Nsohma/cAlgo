#include <stdio.h>
#include <stdlib.h>

#define N 100

void quicksortt(int i, int j, int *A);
int partition(int i, int j, int a, int *A);
int pivot(int i, int j, int *A);
void swap(int i, int j, int *A);

int main(void){
    int A[N];
    for (int i=0; i<10; i++) A[i] = 10 - i;
    for (int i=0; i<10; i++) printf("A[%d]:%d ", i, A[i]);
    puts("");
    quicksortt(0, 9, A);
    for (int i=0; i<10; i++) printf("A[%d]:%d ", i, A[i]);
    return 0;
}

void quicksortt(int i, int j, int *A){
    int pv = pivot(i, j, A);
    if (pv == -1) return;
    int k = partition(i, j, A[pv], A);
    quicksortt(i, k-1, A);
    quicksortt(k, j, A);
}

int partition(int i, int j, int a, int *A){
    //partitify A[i] ... A[j] from a
    //A[i] ... A[k-1] < a , a <= A[k] ... A[j] 
    int l = i, r = j;
    while (l < r+1){
        while (A[l] < a) l++;
        while (A[r] >= a) r--;
        if (l < r+1) swap(l, r, A);
    }
    return l;
}

int pivot(int i, int j, int *A){
    //select A[pv] from A[i] ... A[j] and output pv
    //A[pv] is bigger one of A[i] and A[k] 
    //which is initially different from A[i]
    //if all value are same, output -1
    int k = i;
    int pv = -1;
    while (k < j+1){
        if (A[k] > A[i]){
            pv = k;
            break;
        }
        if (A[i] > A[k]){
            pv = i;
            break;
        }
        k++;
    }
    return pv;
}   

void swap(int i, int j, int *A){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}


