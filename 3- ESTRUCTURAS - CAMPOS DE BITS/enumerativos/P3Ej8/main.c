#include <stdio.h>
#include <stdlib.h>

typedef enum { IZQUIERDA, CENTRO_H, DERECHA } AlineacionHorizontal;
//izq = 0; centro = 1; derecha = 2
typedef enum { ARRIBA=1, CENTRO_V, ABAJO } AlineacionVertical;
//arriba = 1; centro = 2; abajo = 3
typedef enum { DOS=2, CERO=0, UNO, MENOS_UNO=-1, OTRO } Numeros;
//dos = 2; cero= 0; uno = 1; menos_uno = -1; otro= 0
typedef enum { LET_A = 'A', LET_B, LET_Z = 'Z' } Letras; //es con comillas simples pq son caracteres
//let_A = "a"; let_b = "B"; let_Z = "Z"
typedef enum { LETRA_A = 'A', LETRA_B, LETRA_Z = 'Z' } Letras2;
//letraA = 'A'; letraB = 'B'; letraZ = 'Z'

int main()
{
    printf("el valor de uno es: %d \n" , UNO);
    printf("el valor de letB es: %c \n" , LET_B);

    return 0;
}
