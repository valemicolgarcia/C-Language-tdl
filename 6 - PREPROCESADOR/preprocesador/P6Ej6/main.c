#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define AREA_CIRCULO(x) (3.14)*((x)*(x))

    /*Realice un programa que defina una macro AREA_CIRCULO(r) que permita calcular el área de un círculo
    para un radio r. El cuerpo del programa debe generar aleatoriamente 10 valores diferentes que
    representan radios e imprimir el área correspondiente
    */

int main()

{
    srand (time(NULL));
    int radio;

    int i;
    for (i=0;i<10;i++){
        radio = rand () % 10;
        printf ("El radio es %d \n", radio);
        printf("AREA DEL CIRCULO(xin)=%f \n", AREA_CIRCULO(radio));
    }

   // printf("\nAREA DEL CIRCULO(xin)=%f \n", AREA_CIRCULO (radio));
    return 0;
}
