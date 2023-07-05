#include <stdio.h>
#include <stdlib.h>

//OPCION 1-------------------------------------------------------------------------------------------------------
typedef struct persona { //declara el typedef en la misma linea que se declara la estructura. Ahorro en escritura
 char nombre[50];
 long int DNI;
} persona_t;

//OPCION 2-------------------------------------------------------------------------------------------------------
struct persona1 { //estructura Persona que tiene dos campos (dni y nombre)
 char nombre[50];
 long int DNI;
} unaPersona; //declaro variable de tipo persona

typedef struct persona1 persona_V; //define un alias para el tipo persona (redefinicion de tipo para ahorrar en escritura)

int main()
{
    printf("PRACTICA 3, EJERCICIO 2, ANALISIS DE ESTRUCTURAS---\n");


    return 0;
}
