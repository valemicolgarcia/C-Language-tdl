#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

    /*Una vez implementadas todas las funciones de biblioteca, escriba un programa que lea números
    enteros y los inserte en una pila. A continuación, desapile los elementos para verificar si funciona
    correctamente. La lectura finaliza con el ingreso del 0.
            */
int main()
{
    //CREACION DE LA PILA!!!
    Stack pila;
    pila = s_create(); //reservo espacio para la pila

    //APILACION DE LOS ELEMENTOS DE LA PILA.
    int num;
    int apilado;
    printf ("Ingrese un numero para apilar \n");
    scanf ("%d", &num);

    while (num != 0){
        apilado = s_push (&pila, num);
        printf ("Se apilo este elemento: %d \n", apilado);
       printf ("Ingrese un numero para apilar \n");
        scanf ("%d", &num);
    }

    int cant = s_length(pila);
    cant = pila.tamanio;
    printf ("La cantidad de elementos que tiene la pila es: %d \n", cant);
    printf("\n");

    int desapilado;
    //DESAPILO LA PILA!!!
    while (pila.tope != NULL){
        desapilado = s_pop (&pila);
        printf ("Se desapilo este elemento: %d \n", desapilado);
    }

    cant = s_length(pila);
    printf ("La cantidad de elementos que tiene la pila es: %d \n", cant);

    return 0;
}
