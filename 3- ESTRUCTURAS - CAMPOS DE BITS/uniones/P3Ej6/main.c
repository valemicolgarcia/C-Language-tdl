#include <stdio.h>
#include <stdlib.h>

union hack {
        struct {
            short int anio; //2
            char mes; //1
            char dia; //1
        } f;
        int comparo; //4
    };

typedef union hack tiempo_hack;

/*
typedef union hack {  //LA OTRA OPCION PARA DECLARAR
        struct {
            short int anio; //2
            char mes; //1
            char dia; //1
        } f;
        int comparo; //4
    } tiempo_hack;
*/



int main()
{

    //DECLARO DOS FECHAS A COMPARAR
    tiempo_hack x; //fecha 1
    tiempo_hack y; //fecha 2

    x.f.anio = 1;
    y.f.anio = 2;
    y.f.mes = '11';
    x.f.mes = 10;
    y.f.dia = 30;
    x.f.dia = 15;

    printf("El mes de x es: %c \n"+ x.f.mes); //no imprime

    if (x.comparo < y.comparo)
        printf("La fecha 1 es mayor a la 2.");
    else
        printf("La fecha 2 es mayor a la 1.");

    //-----------ahora comparo las fechas

    /*¿Cree que esta implementación funcionaría para todos los compiladores de C sin importar
        la arquitectura del procesador? (Pista: Little endian vs. Big endian)
        PREGUNTAR!!!
    */

    return 0;
}
