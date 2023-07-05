#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

void MaxMinProm (float *, float *, float *, float []);
//le mando variable maximo, minimo, prom y el vector que pedia al principio

int main()
{
    float max, min; //declaro variables para el resultado
    float prom;
    max = -1;
    min = 9999;

    //creo el vector-------------------------------------

    srand(time(NULL));
    float vector [N] = {0};
    int i;
   for (i=0; i<N; i++){ //lo cargo
        vector [i]= rand () % 51;
    }
    printf ("EL VECTOR ES: \n");
    for (i = 0; i<N; i++){ //lo imprimo
        printf( "%f \n", vector[i] );
    }
    //ejecuto el procedimiento
    MaxMinProm (&max, &min, &prom, vector); //mando punteros

    printf( "El promedio es %f \n", prom );
    printf( "El minimo es %f \n", min );
    printf( "El maximo es %f \n", max );

   //--------------------------------------
    return 0;
}

void MaxMinProm (float * max, float * min, float * prom, float v [N] ){

    int i;
    float suma = 0;
    for (i = 0; i<N; i++){

        suma += v[i]; //sumo cada uno de los elemntos del arreglo
        if ( v[i]  < *min)
            *min = v[i]; //minimo
         if ((v[i]) > *max)
            *max = v[i]; //maximo

    }
    *prom = suma/N;
    }
//-------------------------------------------------------------------------
