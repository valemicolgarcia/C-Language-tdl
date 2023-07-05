#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Juego (int , int);
int main()
{ int dado1, dado2;

    srand(time(NULL));
    dado1 = rand() % 11;
    dado2 = rand () % 11;
    Juego (dado1, dado2);

    return 0;
}
void Juego (int dado1, int dado2){
    int suma;
    printf("DADO 1: %d \n" , dado1);
    printf("DADO 2: %d \n" , dado2);
    suma = dado1 + dado2;
    printf("La suma es: %d \n", suma);
    if ((suma == 2)||(suma == 12))
        printf("El jugador pierde");
    else
        if ((suma == 7)||(suma == 11))
            printf("El jugador gana");
        else {
            printf("Arroja dados nuevamente!! \n");
            Juego (rand() % 11, rand() % 11);
        }
}
