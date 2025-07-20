#include <stdio.h>
#include <stdlib.h>

int subsetsum(int *A, int k, int p);

int main(void){
    int A[100], b, ans;
    A[0] = 4; A[1] = 7; A[2] = 5;
    A[3] = 8; A[4] = 2; b = 11;
    ans = subsetsum(A, 4, 11);
    printf("ans:%d\n", ans);
    return 0;
}

int subsetsum(int *A, int k, int p){
    if (k == 0){
        if (p == 0 || p == A[0]) return 1; //yes 
        else return 0; //no
    }
    if (subsetsum(A, k-1, p) || (p - A[k] >= 0 && subsetsum(A, k-1, p-A[k]))){
        printf("subsetsum(A, %d, %d):%d, subsetsum(A, %d, %d):%d \n", k-1,p, subsetsum(A, k-1, p) ,k-1, p-A[k], subsetsum(A, k-1, p-A[k]));
        return 1;
    } else{
        return 0;
    }
}


