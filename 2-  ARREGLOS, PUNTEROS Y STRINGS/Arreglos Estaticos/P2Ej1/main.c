#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main()
{
    int v [N];
    srand(time(NULL));

    int i;
    for (i=0; i<N; i++){
        v[i]= rand () % 51;
    }
    int cantPares = 0;
    int cantImpares = 0;

    for (i=0; i<N; i++){
        if (i % 2){
        //POSICIÓN IMPAR ---> cuento numero pares
            if (!(v[i]%2))
                cantPares ++;
        } else{
        //POSICIÓN PAR ---> cuento numero impares
            if (v[i]%2)
                cantImpares ++;

        }
    }

    for (i=0; i<N; i++){
        printf("%d \n", v[i]);
    }

    printf("CANTIDAD NUMERO PARES en posición impar: %d \n", cantPares);
    printf("CANTIDAD NUMERO IMPARES en posición par: %d \n", cantImpares);


    return 0;
}
