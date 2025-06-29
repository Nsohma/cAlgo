#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a, b;
    int *k = (int *)malloc(sizeof(int));
    a = *k;
    b = a;
    *k = 5;
    printf("a:%d, b:%d, k:%d", a, b, *k);
}
