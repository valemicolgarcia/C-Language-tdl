#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 3
#define N 3

void MultEscalar(int, int[][N]);
void imprimirMatriz (int [][N]);
void cargarMatriz (int [][N]);


int main()
{
    srand(time(NULL));
    int matriz[3][N] = {{0},{0}};
    int c;
    printf("Ingrese un numero: ");
    scanf("%d",&c);
    cargarMatriz(matriz);
    imprimirMatriz(matriz);

    printf("La multiplicacion c*A: \n ");
    MultEscalar(c, matriz);
    imprimirMatriz(matriz);


    return 0;
}
// 2 • [ 1 8 −3 4 −2 5 ] = [ 2 • 1 2 • 8 2 • −3 2 • 4 2 • −2 2 • 5 ] = [ 2 16 −6 8 −4 10]
void MultEscalar(int c, int m[][N]) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            m[i][j] *= c;
        }
    }
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
