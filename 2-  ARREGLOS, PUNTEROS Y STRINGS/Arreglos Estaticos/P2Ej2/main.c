#include <stdio.h>
#include <stdlib.h>
#define N 5
#include <time.h>

float Promedio (float []);
float Minimo (float []);
float Maximo (float []);

int main()
{
    srand(time(NULL));
    float v [N] = {0};
    int i;

    for (i=0; i<N; i++){
        v[i]= rand () % 51;
    }

    for (i = 0; i<N; i++){
        printf( "%f \n", v[i] );
    }

    printf( "El promedio es %f \n", Promedio (v) );
    printf( "El minimo es %f \n", Minimo (v) );
    printf( "El maximo es %f \n", Maximo (v) );

    return 0;
}

float Promedio (float v []){
    int i;
    float suma = 0;

    for (i = 0; i<N; i++){
        suma += v[i];
    }

    return (suma/N);}


float Minimo (float v[]){

    float min = 9999;
    for (int i= 0; i< N; i++){
        if ( v[i]  < min)
            min = v[i];
            }
    return min;
    }

float Maximo (float v []){

    float max = -1;

    for (int i= 0; i< N; i++){
        if ((v[i]) > max)
            max = v[i];
            }
    return max;

    }
