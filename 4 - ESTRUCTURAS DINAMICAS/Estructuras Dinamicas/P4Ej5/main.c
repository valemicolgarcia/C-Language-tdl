#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 101

/*Escriba un programa que reserve en forma dinámica un arreglo de 100 caracteres. A continuación, lea
10 oraciones utilizando la función gets e informe para cada una de ellas la cantidad de letras
minúsculas y de letras mayúsculas que la componen. Utilice el arreglo creado como variable temporal
para procesar cada oración. Por último, libere la memoria reservada dinámicamente.
*/



void reservarMemoria (char ** , int); //reserva espacio en el vector
void analizo (char ** , int); //reserva espacio en el vector

int main()
{

    char * ptr = NULL; //declaro el puntero de char
    reservarMemoria(& ptr, N); //le paso la direccion del puntero y reservo memoria dinamica

    for (int i=0; i<10; i++){
        analizo(&ptr,N);

    }


    //libera la memoria de todo
    free (ptr);

    return 0;
}
//------------------RESERVA MEMORIA--------------------------
void reservarMemoria (char  ** ptr, int n) {
    *ptr = (char *) malloc(n * sizeof(char)); // lleno y se inicializa con basura

}
//------------------ANALIZO ORACION--------------------------

void analizo (char  ** ptr, int n) {
    gets (*ptr); //leo la oracion
    int minuscula = 0;
    int mayuscula = 0;

    int tamanio = strlen (*ptr);


    for (int i=0;  i< tamanio;i++){

        if  ((((*ptr)[i]) - 'a' >= 0) && ((*ptr)[i] - 'z' <= 0))
            minuscula ++;
        else
            if ((((*ptr)[i]) - 'A' >= 0) && ((*ptr)[i] - 'Z' <= 0))
                mayuscula++;

    }

    printf("La cantidad de MAYUSCULAS es %d \n", mayuscula);
    printf("La cantidad de minusuclas es %d \n", minuscula);



}





