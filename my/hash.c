#include <stdio.h>
#include <stdlib.h>

int h(char *x);

int main(void){
    char *x = (char *)malloc(sizeof(char)*10);
    x[0] = 'a';
    x[1] = 'b';
    x[2] = 'c';
    x[3] = '\0';
    h(x);
    return 0;
}

int h(char *x){
    int sum, memo;
    while (*x){
        printf("%c", *x);
        memo = *x;
        sum += memo; 
        x++;
    }
    return sum;
}

