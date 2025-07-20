#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float zero = 0.001;
float delta = 0.0001;

float newton(float xinit);
float f(float x);
float df(float x);

int main(void){
    float xinit = 5.0;
    float a = newton(xinit);
    printf("%f", a);
    return 0;
}

float newton(float xinit){
    if (fabsf(f(xinit)) < delta) return xinit;

    return newton(xinit - (f(xinit) / df(xinit)));
}

float f(float x){
    float fx;
    fx = x*x*x - 10.0;
    return fx;
}

float df(float x){
    float d = 3 * x*x;
    return d;
}

