#include <stdio.h>
#include <stdlib.h>

#define N 100
#define M 100

//int subsetsum(int *A, int k, int p);
int dpssum(int *A, int k, int p, int memo[][M]);

int main(void){
    int A[100], b, ans, memo[N][M];
    A[0] = 0; A[1] = 7; A[2] = 5;
    A[3] = 8; A[4] = 2; b = 11;
    for (int i=0; i<10; i++){
        for (int j=0; j<20; j++) memo[i][j] = -1;
    }
    ans = dpssum(A, 4, 11, memo);
    printf("ans:%d\n", ans);
    return 0;
}

//not dp but recursive
//int subsetsum(int *A, int k, int p){
//    if (k == 0){
//        if (p == 0 || p == A[0]) return 1; //yes 
//        else return 0; //no
//    }
//    if (subsetsum(A, k-1, p) || (p - A[k] >= 0 && subsetsum(A, k-1, p-A[k]))){
//        printf("subsetsum(A, %d, %d):%d, subsetsum(A, %d, %d):%d \n", k-1,p, subsetsum(A, k-1, p) ,k-1, p-A[k], subsetsum(A, k-1, p-A[k]));
//        return 1;
//    } else{
//        return 0;
//    }
//}

//adapt dp (memo calcurate result and use it)
int dpssum(int *A, int k, int p, int memo[][M]){
    if (memo[k][p] != -1) return memo[k][p];
    if (k == 0){
        if (p == 0 || p == A[0]) memo[k][p] = 1; //yes 
        else memo[k][p] = 0; //no
    }
    else if (dpssum(A, k-1, p, memo) || (p - A[k] >= 0 && dpssum(A, k-1, p-A[k], memo))){
        memo[k][p]=1;
    } else{
        memo[k][p]=0;
    }
    return memo[k][p];
}



