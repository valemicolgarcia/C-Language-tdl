#include <stdio.h>
#include <stdlib.h>

    /*¿Qué estructura/s se puede/n modelar con la variable m?
   //se puede modelar una matriz dinamica reservando memoria como un bloque homogeneo

    b. ¿Se puede utilizar a m como si fuera una matriz, simulando el acceso por filas y columnas? En ese
    caso, ¿cómo se podría acceder a sus elementos?
    //se puede acceder a sus elementos utilizando un desplazamiento a partir de la direccion inicial

    c. Escriba un programa que trabaje con una matriz de enteros utilizando las declaraciones
    anteriores sin importar el orden de acceso a cada dimensión (fila y columna o columna y fila).
    Cargue a m con valores leídos desde teclado y luego imprima sus valores en pantalla para
    verificar que se cargó correctamente. Por último, libere la memoria reservada.
   */

//ARREGLO BIDIMENSIONAL

//PROTOTIPOS
int * cargarMatriz (int x, int y);
void imprimirMatriz ( int * matriz, int x, int y);

   //MATRICES DINAMICAS DE UN SOLO INDICE
int main()
{
    //CARGA DE MATRIZ
    int x=2, y=3;
    int *m;
    m= cargarMatriz(x,y);
    printf("\n");
    //IMPRESION DE MATRIZ
    imprimirMatriz (m,x,y);
    //LIBERO LA MEMORIA
    free (matriz);


    return 0;
}

int * cargarMatriz (int x, int y){

       //ASIGNO MEMORIA PARA LA MATRIZ

       int *matriz = (int*) malloc (x*y*sizeof (int)); //matriz como unico bloque homogeneo


       //CARGO ELEMENTOS DE LA MATRIZ
       int n;
       for (int i=0; i<x; i++){ //---> recorro filas
            for (int j=0; j<y; j++){ //---> recorro columnas
                printf("Ingrese numero para agregarlo a la matriz: \n");
                scanf("%d", &n);
                matriz[i*y+j] = n; //---> fila actual * nro de columnas + columna actual
            }
       }
        printf("MATRIZ CARGADA \n");


return matriz;

}

void imprimirMatriz ( int * matriz, int x, int y){

    //IMPRIMO VALORES DE LA MATRIZ
    printf("IMPRIMO MATRIZ \n");
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
           printf("%d", matriz [i*y+j]);
        }
        printf("\n");
    }


}




