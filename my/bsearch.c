#include <stdio.h>
#include <stdlib.h>

#define N 100

//char mybsearch(int x, int *A, int i, int n);
char mybsearch(int x, int *A, int n);

int main(void){
    int A[N];
    char a;
    for (int i=0; i<10; i++) A[i] = i+1;
    //a = mybsearch(1, A, 0, 10);
    a = mybsearch(3, A, 10);
    printf("%c", a);
    return 0;
}

// --- recursive ---
//char mybsearch(int x, int *A, int i, int n){
//    int mid = (n+i)/2;
//    if (i >= n) return 'n';
//    else if (A[mid] == x) return 'y';
//    else if (A[mid] > x) return mybsearch(x, A, i, mid);
//    else if (A[mid] < x) return mybsearch(x, A, mid+1, n);
//}

char mybsearch(int x, int *A, int n){
    int l = 0, r = n-1;
    int mid;
    while (l < r){
        mid = (l + r) / 2;
        if (A[mid] == x) return 'y';
        else if (A[mid] > x) r = mid;
        else if (A[mid] < x) l = mid;
    }
    return 'n';
}

