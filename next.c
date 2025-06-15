#include <stdio.h>
void next(int *x, int n);

int main(void){
    int x[6] = {1, 1, 1, 1, 1, 1};
    int y[6] = {1, 0, 0, 1, 0, 1};
    int n = 6;
    next(x, n);
    printf("x[0] = 0\nx = ");
    for (int i = 0; i<n; i++) printf("%d ", x[i]);
    printf("\n");
    next(y, n);
    printf("y[0] = 1\ny = ");
    for (int i = 0; i<n; i++) printf("%d ", y[i]); 
    printf("\n");
    return 0;
}

void next(int *x, int n){
    int check = 0, k = 0;
    //error check whether x = [1,1,...,1]
    for (int j=0; j<n ; j++){
        if (x[j] == 0) check++;
    }
    if (check == 0) return;

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
}
