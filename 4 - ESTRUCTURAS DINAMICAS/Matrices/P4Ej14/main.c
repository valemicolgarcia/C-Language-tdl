#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    /*Escriba un programa que lea desde teclado un valor entero n y reserve memoria para una matriz
    triangular inferior de orden n de enteros. Como se desea ahorrar espacio de almacenamiento, no se
    deben almacenar los elementos cuyo valor es 0, es decir, sólo se reservará memoria para los valores
    del triángulo inferior de la matriz. Luego, inicialice la estructura con valores aleatorios entre 0 y 20
    e imprímala en pantalla. Por último, libere la memoria reservada.
    */

//PROTOTIPOS
int * inicializarMatriz (int orden, int cant);
void cargarMatriz (int ** matrizTriangular, int cant);
void imprimirMatriz (int * matrizTriangular, int orden);
void liberarMemoria (int * matriz);

int main()
{
    srand(time(NULL));

    //ORDEN DE LA MATRIZ
    int orden;
    printf("Ingrese orden de la matriz \n");
    scanf ("%d", &orden);
    printf("\n");
    //CANTIDAD DE ELEMENTOS RESERVADOS PARA MATRIZ
    int cant;
    for (int i=1; i<=orden; i++){
        cant+=i;
    }
    printf("La cantidad de espacios a reservar es de: %d \n", cant);
    /*
    cant = 1
    cant = 1+2
    cant = 1+2+3
    */

    //INICILIZACION DE LA MATRIZ
    int * matrizTriangular = inicializarMatriz(orden,cant);

    //CARGO ELEMENTOS DE LA MATRIZ
    cargarMatriz (& matrizTriangular, cant);

    //IMPRIMIR MATRIZ
    imprimirMatriz (matrizTriangular, orden);

    //LIBERAR MEMORIA
    liberarMemoria (matrizTriangular);


    return 0;
}

int * inicializarMatriz (int orden, int cant){

    int *matriz = (int*) malloc (cant*sizeof (int)); //reservo memoria

return matriz;
}


void cargarMatriz (int ** matrizTriangular, int cant){

    int n;
    for (int j=0; j<cant; j++){ //---> recorro columnas
        printf("Ingrese numero para agregarlo a la matriz: \n");
        scanf("%d", &n);
        (*matrizTriangular)[j] = n;
      //  (*matrizTriangular)[j] = rand()%21;
        }
    printf("MATRIZ CARGADA \n");

}

void imprimirMatriz (int * matrizTriangular, int orden){
    int cant = 1;
    int pos =0;
    printf("\n");
    printf("IMPRIMO MATRIZ TRIANGULAR: \n");
    for (int i=1; i<=orden; i++){

        for (int x=0; x<cant;x++){ //imprimo los elementos cargados
            printf("%d ", matrizTriangular[pos]);
            pos++; //posicion del vector a imprimir
        }
        for (int x=0; x<(orden-cant); x++){ //imprimo ceros
            printf("0 ");
        }
        cant++; //cantidad de elementos a imprimir

        printf("\n");

    }
}

void liberarMemoria (int * matriz){
    printf("\n");
    free (matriz);
    printf("MEMORIA LIBERADA \n");

}
