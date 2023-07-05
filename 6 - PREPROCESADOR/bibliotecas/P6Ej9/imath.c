
#include "imath.h"

int potencia(int x, int y){
    if (y == 0){
        return 1;
    }
    else {
        return (x * potencia (x,y-1));
    }
}

int cuadrado (int x){
return (x*x);
}

int cubo(int x) {
    return (x*x*x);
}

int absoluto(int i){
    if (i<0)
        return (i*(-1));
    else
        return i;
}

int factorial (int i){
    if (i<=1)
        return 1;
    else
        return (i * factorial (i-1));
}

int sumatoria (int i){
    int j;
    int suma;
    for (j=0;j<=i;j++){
        suma+=j;
    }
    return suma;
}

int multiplo (int x, int y){
    if (x % y == 0)
        return 1;
    else
        return 0;
}

int divisor (int x, int y){
    if (y % x == 0)
        return 1;
    else
        return 0;
}
int par (int i){
    if (i%2 == 0)
        return 1;
    else
        return 0;
}

int impar (int i){
    if (i%2 != 0)
        return 1;
    else
        return 0;
}




