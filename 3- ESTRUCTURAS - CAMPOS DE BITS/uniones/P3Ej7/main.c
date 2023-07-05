#include <stdio.h>
#include <stdlib.h>

struct estudiante {
    char apellido [20];
    char nombre [20];
    char legajo [8];
    int nacionalidad;
    union identificacion {
        int dni;
        char pasaporte [10];
        } id;
};
//PROTOTIPOS DE FUNCIONES
void leerEstudiante (struct estudiante *); //parametro por referencia
void imprimirEstudiante (struct estudiante); //parametro por valor


int main()
{
    struct estudiante e;
    leerEstudiante (&e);
    imprimirEstudiante (e);

    return 0;
}

void leerEstudiante (struct estudiante * e){
    printf("\n");
    printf("Ingrese apellido del estudiante \n");
    scanf("%s", e->apellido);
    printf("Ingrese nombre del estudiante \n");
    scanf("%s", e->nombre);
    printf("Ingrese legajo del estudiante \n");
    scanf("%s", e->legajo);
    printf("Ingrese 1 si el estudiante es argetino o 2 si es extranjero\n");
    scanf("%d", &(e->nacionalidad));
    if ( (e->nacionalidad) == 1){
        printf("Ingrese dni del estudiante argentino: \n");
        scanf("%d", &(e->id.dni));
    }
    else
        if ((e->nacionalidad) == 2){
            printf("Ingrese identificacion del estudiante extranjero \n");
            scanf("%s", ((e->id).pasaporte));
        }

    printf("\n");
}


void imprimirEstudiante (struct estudiante e){
printf("\n");
printf("El apellido del estudiante es: %s \n" , e.apellido);
printf("El nombre del estudiante es: %s \n" , e.nombre);
printf("El legajo del estudiante es: %s \n" , e.legajo);
if (e.nacionalidad == 1)
    printf("La identificacion del estudiante es: %d \n" , e.id.dni);
else
    if (e.nacionalidad == 2)
        printf("La identificacion del estudiante es: %s \n" , e.id.pasaporte);
printf("\n");
}
