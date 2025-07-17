#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float epsilon = 0.0001;
float delta = 0.0001;

float findzero(float a, float b);
float f(float x);

int main(void){
    float a, b, x;
    a = 0.0; b = 10.0;
    x = findzero(a, b);
    printf("ans : %f\n", x);
    return 0;
}

float findzero(float a, float b){
    float xL, xR, xM, fx;
    xL = a; xR = b;
    xM = (xL + xR) / 2;
    while (fabsf(f(xM)) > delta && xR - xL > epsilon){
        if (f(xM) > 0) xR = xM;
        else if (f(xM) < 0) xL = xM;
        xM = (xL + xR) / 2;
    }
    return xM;
}

float f(float x){
    float fx;
    fx = x*x*x -10.0;
    return fx;
}
