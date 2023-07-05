#include <stdio.h>
#include <stdlib.h>
/* Escriba un programa que lea desde teclado dos valores enteros n y m, y luego reserve memoria en
forma dinámica para una matriz de enteros de n filas por m columnas. Inicialice la matriz creada con
valores ingresados por teclado. Una vez inicializada, imprima las posiciones de todos aquellos valores
múltiplos de 3. Por último, libere la memoria reservada.
Nota: modularice la reserva de memoria, la inicialización, la impresión de las posiciones con valores
múltiplo de 3 y la liberación de memoria.
*/


void imprimirMatriz (int **M, int f, int c);
int ** inicializarMatriz (int n, int m);
void imprimirMultiplo (int **M, int f, int c);
void liberarMemoria (int **M, int f, int c);

int main()
{
    int n;
    printf("Lea un numero de filas \n");
    scanf("%d", &n); //leo el numero n desde teclado

    int m;
    printf("Lea un numero de columnas \n");
    scanf("%d", &m); //leo el numero n desde teclado
    int ** MD = inicializarMatriz (n,m);
    imprimirMatriz(MD,n,m);
    imprimirMultiplo (MD, n, m);
    liberarMemoria (MD,n,m);



    return 0;
}

int ** inicializarMatriz (int n, int m){

    int ** MD;
    //RESERVA DE MEMORIA
    MD = (int **) malloc (n* sizeof(int*));
    for (int i=0; i<n; i++){

        MD [i] = (int*)malloc (m*sizeof(int));

    }
    //LLENO LA MATRIZ CON NUMEROS LEIDOS DE TECLADO
    int numero;
    for (int f=0; f<n; f++){
        for (int c=0; c<m; c++){
            printf("Lea un numero desde teclado \n");
            scanf("%d", &numero); //leo el numero n desde teclado
            MD [f][c] = numero;
        }
    }
    return MD;
}

void imprimirMatriz (int **M, int f, int c){
    printf("MATRIZ COMPLETA: \n");
    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++){
            printf("%d", M[i][j]);
        }
        printf("\n");
    }
}

void imprimirMultiplo (int **M, int f, int c){

    printf("IMPRIMO MULTIPLO: \n");
    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++){
            if (!(M[i][j]%3)){
               printf("El numero es %d \n", M[i][j]);
                printf("La posicion es (%d,%d) \n", i,j);
            }

        }
    }
}

void liberarMemoria (int **M, int f, int c){

    printf("MEMORIA LIBERADA \n");
    for (int i=0;i<f;i++){
        free(M[i]);
    }
    free (M);

}



