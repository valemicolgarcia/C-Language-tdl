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
    if (num <= 1)
        fact = 1;
    else
        fact = num * factorial (num - 1);

   return fact;
}

