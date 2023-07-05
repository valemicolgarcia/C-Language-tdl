#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num; int millas;

    printf("Ingrese distancia en kilometros: \n");
    scanf ("%f" , &num );

    millas = (num / 1.61);
    printf ("El equivalente en millas es: %d /n", millas);
    return 0;
}
