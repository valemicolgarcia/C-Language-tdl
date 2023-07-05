#include <stdio.h>
#include <stdlib.h>
#define size 25 //precompilacion

    void imprimir(int * v, int cant){
         int i;
         for (i=0; i<cant; i++){
            printf("v[%d]= %d \n", i, v[i]);
        }
    //el codigo no compliaba porque no se puede poner el nombre de la
    // del define en los parametros.
    //En la funcion se puede usar el define pero no es buena practica
    }
    int main(){
         int v[size];
         imprimir(v, size); //el reemplazo es de precompilacion.

         //se reemplazan todas las instancias de las constantes definidas en el define.

         return 0;
    }

