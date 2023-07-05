#include <stdio.h>
#include <stdlib.h>

int factorial (int);
int main()
{ int num;
    printf("Ingrese numero entero\n");
    scanf ("%d" , &num);


    printf ("El factorial es: %d" , factorial (num));
    return 0;
}
int factorial(int num){
    int fact;
    fact = 1;
    for (int i = num; i >= 1; i-- ){
        fact *= i;
    }
   return fact;
}
