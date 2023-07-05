#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i;
    srand(time(NULL));
    printf ("NUMEROS ALEATORIOS: ");
    for (i=0; i<15; i++) {
        printf ("%d - ", rand());
    }
    return 0;
}
