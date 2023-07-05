/*Escriba un programa que lea un número entero n y luego reserve memoria en forma dinámica para
un arreglo de n elementos double. Inicialice las posiciones del arreglo a partir de valores ingresados
por teclado y a continuación imprima el promedio de todos ellos.
a. Empleando notación de arreglos.
b. Empleando notación de punteros.
Por último, libere la memoria reservada.*/


#include <stdio.h>
#include <stdlib.h>

void f (double ** p, int n); //reserva espacio en el vector
void promedio (double  * ptr, int n);
void imprimir (double  * ptr, int n);

int main()
{
    double * ptr = NULL; //declaro el puntero

    int n;
    printf("Lea un numero desde teclado \n");
    scanf("%d", &n); //leo el numero n desde teclado

    f(&ptr, n); //le paso la direccion del puntero

    imprimir (ptr, n);

    promedio (ptr, n);
    free (ptr); //libero memoria

    return 0;
}
//--------------------------------------------
void f (double  ** ptr, int n) {

    *ptr = (double *) malloc(n * sizeof(double)); //reserva memoria

    double num;
    printf("Lleno el vector dinamico: \n");

    for (int i=0; i<n; i++){
        printf("Lea un numero desde teclado \n");
        scanf("%lf", &num); //leo el numero n desde teclado
       // (*ptr)[i] = num; //version de punteros
       *((*ptr)+i) = num;
    }

}

//---------------------------------------------
void imprimir (double  * ptr, int n) {

    printf("Imprimo los numeros del vector: \n");
    for (int i=0; i<n; i++){
     // printf("%f \n" , ptr[i]);
      printf("%f \n" , *(ptr+i));
    }
}

//----------------------------------------------
void promedio (double  * ptr, int n) {

    double prom;
    printf("Calculo el promedio \n");
    double suma = 0;
    for (int i=0; i<n; i++){
      //suma+= ptr[i];
      suma+= *(ptr+i);
    }
    prom = suma / n;
    printf("El promedio del arrelo dinamico es: %lf \n",prom);
}
