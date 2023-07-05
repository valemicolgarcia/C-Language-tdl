#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 3
#define N 3

//PROTOTIPOS DE FUNCIONES-----------
void cargarMatriz (int [][N]);
void imprimirMatriz (int [][N]);
void imprimirMatrizTranspuesta (int [][N]);
void transpuesta (int [][N]);

int main()
{
    srand(time(NULL));
    int matriz[M][N] = {{0},{0}}; //declaramos matriz
    cargarMatriz(matriz);
    imprimirMatriz (matriz);

   printf("TRANSPUESTA: \n");
   // transpuesta(matriz);
    imprimirMatrizTranspuesta(matriz);

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

void imprimirMatrizTranspuesta (int m [][N]){
int i, j;
for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                printf(" %d -", m[j][i]);
            }
        printf("\n");
    }
}

void transpuesta (int m [][N]){
int i, j;
int aux [M][N]= {{0},{0}}; //matriz cuadrada

for (i = 0; i < M; i++) { //recorro la fila
            for (j = 0; j < N; j++) { //recorro la columna
                    aux [i][j]= m [i][j];
            }
    }

for (j = 0; j < N; j++) { //recorro la columna
            for (i = 0; i < M; i++) { //recorro la fila
                    m [i][j]= aux [j][i];
            }
    }
m = aux;

}


