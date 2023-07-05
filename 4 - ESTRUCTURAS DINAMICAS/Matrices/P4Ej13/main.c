#include <stdio.h>
#include <stdlib.h>

//ARREGLO UNIDIMENSIONAL

//PROTOTIPOS
int * cargarArreglo (int x);
void imprimirArreglo ( int * vector, int x);

//MATRICES DINAMICAS DE UN SOLO INDICE
int main()
{
    //CARGA DE VECTOR
    int x=2;
    int *v;
    v= cargarArreglo(x);
    printf("\n");
    //IMPRESION DE VECTOR
    imprimirArreglo (v,x);
    //LIBERO LA MEMORIA
    free (v);


    return 0;
}

int * cargarArreglo (int x){

       //ASIGNO MEMORIA PARA LA MATRIZ

       int *vector = (int*) malloc (x*sizeof (int)); //vector unidimensional


       //CARGO ELEMENTOS DEL VECTOR
       int n;
       for (int i=0; i<x; i++){ //---> recorro filas
            printf("Ingrese numero para agregarlo a la matriz: \n");
            scanf("%d", &n);
            vector[i] = n;
       }
        printf("ARREGLO UNIDIMENSIONAL CARGADO \n");


return vector;

}

void imprimirArreglo ( int * vector, int x){

    //IMPRIMO VALORES DE LA MATRIZ
    printf("IMPRIMO VECTOR \n");
    for (int j=0;j<x;j++){
       printf("%d", vector [j]);
    }

}
