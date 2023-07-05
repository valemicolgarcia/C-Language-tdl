#include <stdio.h>
#include <stdlib.h>
void minMax (int, float *, float *);
int main()
{   int n;
    float min;
    float max;
    max = -1;
    min = 9999;
    printf("Ingrese un numero(veces)  \n");
    scanf ("%d" , &n);
    minMax (n, &min, &max);
    printf ("El minimo es %f" , min);
    printf ("El maximo es %f" , max);

    return 0;
}
//funcionnnnnnnnnn

void minMax (int n, float *min, float *max) {
    float num;
    while (n != 0) {
        printf ("Ingrese un numero flotante");
        scanf ("%f" , &num);

        if (num > *max)
            *max = num;
        if (num < *min)
                *min = num;
        n--;
    }

}

