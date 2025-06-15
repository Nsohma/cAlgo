#include <stdio.h>

int gcd(int a0, int a1);

int main(void){
    int a0, a1, temp;
    //start input from a0
    printf("Type in the first integer.\n");
    scanf("%d", &a0);
    printf("a0 = %d\n", a0);
    //a1
    printf("Type in the second integer.\n");
    scanf("%d", &a1);
    printf("a0 = %d\n", a1); //finish input

    if (a0 < a1){//normalization
        temp = a0; a0 = a1; a1 = temp;
    }
    printf("GCD = %d\n", gcd(a0, a1));
    return 0;
}

/* recursive program
int gcd(int a0, int a1){
    if (a0 % a1 > 0){
        return gcd(a1, a0 % a1);
    }
    else{
        return a1;
    }
}*/

//normal
int gcd(int a0, int a1){
    int a, b, temp;
    a = a0; b = a1;
    while (b != 0){
        temp = a % b; a = b; b = temp;
    }
    return a;
}

