#include <stdio.h>
#include <stdlib.h>
//demonstrate difference between shallow copy and deep copy
int deep(int a);
int shallow(int *a);

int main(void){
    int a0, a1, a2, a3, b;
    int *c;
    a1 = 0; a0 = 0; a2 = 0, a3 = 0;
    //deep copy
    b = a0; b++;//  <- change value which is different address from a0
    printf("normal status -> a0 : %d and a1 : %d\n", a0, a1);
    //shallow copy
    c = &a1; (*c)++;//  <- change value which is same address as a1
    puts("main:");
    printf("deep copy -> a0 : %d and b : %d, ", a0, b);
    printf("shallow copy -> a1 : %d and *c : %d\n", a1, *c);
    puts("\nfunction:");
    deep(a2);
    shallow(&a3);
    printf("deep copy -> a2 : %d, ", a2);
    printf("shallow copy -> a3 : %d\n", a3);
    return 0;
}

int deep(int a){
    a++;
    return a;
}

int shallow(int *a){
    (*a)++;
    return *a;
}

