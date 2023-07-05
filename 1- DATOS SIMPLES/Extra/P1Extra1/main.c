#include <stdio.h>
#include <stdlib.h>
#define CANT 5

void minimos (int, int, int *, int *);
int main()
{   int i, cod, cant;
    int min1, min2, contador;
    float porcentaje;
    min1 = 0;
    min2 = 0;
    contador = 0;
    for (i = 0; i<CANT; i++) {
        printf("Ingrese codigo \n ");
        scanf ("%d", &cod);
        printf("Ingrese cantidad \n ");
        scanf ("%d" , &cant);
        minimos (cod, cant, &min1, &min2);
        if (cant > 40)
            contador ++;
    }
    porcentaje = (((float) contador) / CANT * 100);
    printf ("El primer minimo es %d \n" , min1);
    printf ("El segundo minimo es %d \n" , min2);
    printf ("El porcentaje es: %f ", porcentaje);
    return 0;
}
void minimos (int cod, int cant, int *min1, int *min2)
{static int cantMin1 = 9999;
static int cantMin2 = 9999;

    if  (cant < cantMin1) {
        *min2 = *min2;
        cantMin2 = cantMin1;
        *min1 = cod;
        cantMin1 = cant;
    }
    else
        if (cant < cantMin2) {
            *min2 = cod;
            cantMin2 = cant;
        }
}
