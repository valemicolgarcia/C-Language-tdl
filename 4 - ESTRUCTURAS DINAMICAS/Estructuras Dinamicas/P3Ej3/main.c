#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

Escriba un programa que lea un número entero n desde teclado y luego reserve memoria en forma
dinámica para un arreglo de n enteros. Inicialícelo con valores aleatorios y a continuación calcule e
imprima el máximo número almacenado. Por último, libere la memoria reservada dinámicamente.
Nota: Modularice la reserva de memoria, la inicialización y el cálculo del máximo
*/
void imprimir (int * p, int n);
void maximo (int * p, int n);
void f (int ** p, int n); //reserva espacio en el vector
int main()
{
    srand (time(NULL));

    int * ptr = NULL; //declaro el puntero
    int n;
    printf("Lea un numero desde teclado \n");
    scanf("%d", &n); //leo el numero n desde teclado
    f(& ptr, n); //le paso la direccion del puntero

    imprimir (ptr, n);
    maximo (ptr, n);
    //libera la memoria de todo
    free (ptr);

    return 0;
}
//--------------------------------------------
void f (int  ** ptr, int n) {
    *ptr = (int *) malloc(n * sizeof(int)); // lleno

    for (int i=0; i<n; i++){
        (*ptr)[i] = rand() % 51; //inicializo
    }

}
//---------------------------------------------
void imprimir (int  * ptr, int n) {

    printf("Imprimo los numeros del vector: \n");
    for (int i=0; i<n; i++){
      printf("%d \n" , ptr[i]);
    }
}
//----------------------------------------------
void maximo (int  * ptr, int n) {
    int max = -1;

    printf("Calculo el maximo ");
    for (int i=0; i<n; i++){
      if ((ptr[i])>max)
        max = ptr [i];
    }
    printf("%d",max);
}
