#include <stdio.h>

#define N 100
enum yn {yes, no};
enum yn ssum(int *a, int b, int *x, int n);
int next(int *x, int n);

int main(void){
    int a[N], x[N], b;
    int n, j;
    FILE *file;

    //file open
    file = fopen("ssumdata", "r");

    //input n
    fscanf(file, "%d", &n);
    printf("n = %d\na = ", n);

    //input a[N] from file
    for (j=0; j<n; j++){
        fscanf(file, "%d", &a[j]);
    }
    //confirm a[N] by output
    for (j=0; j<n; j++){
        printf("%d ", a[j]);
    }
    printf("\n");

    //input b
    fscanf(file, "%d", &b);
    //confirm b
    printf("b = %d\n", b);

    //run ssum
    if (ssum(a, b, x, n) == yes){
        printf("Yes\nx = ");
        for (j=0; j<n; j++) printf("%d", x[j]);
        printf("\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}

enum yn ssum(int *a, int b, int *x, int n){
    //SUBSET-SUM algorism by enumeration method
    int j, full, temp;
    //initialize x array
    for (j=0; j<n; j++) x[j] = 0;

    while (1){
        temp = 0;
        for (j=0; j<n; j++) temp += a[j] * x[j];
        if (temp == b) return yes;
        if (next(x, n)) break;
    }
    return no;
}

int next(int *x, int n){
    int check = 0, k = 0;
    //error check whether x = [1,1,...,1]
    for (int j=0; j<n ; j++){
        if (x[j] == 0) check++;
    }
    if (check == 0) return 1;

    //x += 1
    if (x[0] == 0){
        x[0]+= 1;
    }else if (x[0] == 1){
        x[0] = 0;
        while (x[++k] == 1){
            x[k] = 0;
        }
        x[k] = 1;
    }
    return 0;
}


