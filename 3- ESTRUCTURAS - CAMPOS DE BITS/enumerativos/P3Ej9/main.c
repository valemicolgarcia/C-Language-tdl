#include <stdio.h>
#include <stdlib.h>

typedef enum {DOMINGO, LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO} DiasSemana;
void imprimirDia (int);
int main()
{
    DiasSemana dia; //declaro dia de tipo enum
    dia = DOMINGO;
    printf("%d" , dia);
    imprimirDia (dia);
    return 0;
}
void imprimirDia (int dia){
//dia = LUNES;
printf("%d" , dia);
}
