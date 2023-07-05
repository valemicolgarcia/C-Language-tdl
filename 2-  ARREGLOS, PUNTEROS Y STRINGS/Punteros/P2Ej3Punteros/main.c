#include <stdio.h>
#include <stdlib.h>

int main()
{
     int x[5]={1,2,3,4,5}; //vector de numeros 1,2,3,4,5
     int * p = x;  //a lo que apunta p le pongo el primer elemento del vcetor

     printf("La direccion memoria de p es %p \n", &p); //direccion de la variable &
     printf("La direccion la que apunta p es %p \n", p); //direccion del vector
     printf("El valor al que apunta p es %d \n", *p); //valor del vector
     p++;
     printf("La direccion memoria de p ahora es %p \n", &p); //no cambia la direccion
     printf("La direccion la que apunta p ahora es %p \n", p); //si sumo valor a p, cambia lo que apunta
     printf("El valor al que apunta p ahora es %d \n", *p); //valor del vector

    /*¿Puede explicar qué significado tienen los valores impresos?
    ¿Qué ocurre cuando se incrementa en uno el puntero “p”?
    */
    return 0;
}
