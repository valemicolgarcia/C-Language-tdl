#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 3
#define N 3

//prototipos
void cargarMatriz (int [][N]);
void imprimirMatriz (int [][N]);
void suma (int [][N], int [][N], int [][N]);

int main()
{
    printf("MATRIZ 1: \n");
    srand(time(NULL));
    int matriz1[M][N] = {{0},{0}}; //declaramos matriz
    cargarMatriz(matriz1);
    imprimirMatriz (matriz1);
    printf("   \n");
    printf("MATRIZ 2: \n");
    int matriz2[M][N] = {{0},{0}}; //declaramos matriz
    cargarMatriz(matriz2);
    imprimirMatriz (matriz2);
    int matriz3[M][N] = {{0},{0}}; //declaramos matriz 3
    suma(matriz1,matriz2,matriz3);
    printf("   \n");
    printf("MATRIZ 3: \n");
    imprimirMatriz (matriz3);


    return 0;
}

void cargarMatriz (int m [][N]){

int i, j;
    for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                m[i][j] = rand() % 51;
            }
    }

}

void imprimirMatriz (int m [][N]){

int i, j;
for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                printf(" %d -", m[i][j]);
            }
        printf("\n");
    }
}

void suma (int m1[][N], int m2[][N], int m3 [][N]){

int i, j;
for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                m3 [i][j] = m2 [i][j] + m1 [i][j];
            }
        printf("\n");
    }
}
