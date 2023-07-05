//diferencia entre tipos de arreglo

/*#include <stdio.h>
#include <stdlib.h>
#define N 50
int main() {
 int arreglo1[N]; //declaro un arreglo estatico
 return 0;
}

//se reserva memoria en complilacion
//limite de tamaño: n*4
//no se puede cambiar el tamaño en ejecucion
//no se puede liberra la memoria reservada
//el nombre del arreglo no puede apuntar a otra direccion
*/

/*
#include <stdio.h>
#include <stdlib.h>
int main() {
 int n;
 scanf("%d",&n);
 // el usuario ingresa 50
 int arreglo3[n]; //un arreglo de longitud variable de 50 elementos
 return 0;

//se reserva memoria en ejecucion
//limite de tamaño: n*4
//no se puede cambiar el tamaño en ejecucion
//no se puede liberra la memoria reservada
//el nombre del arreglo no puede apuntar a otra direccion
}*/

//Código 3:

#include <stdio.h>
#include <stdlib.h>
#define N 50
int main() {
 int * arreglo2 = (int *) malloc (N*sizeof(int)); //arreglo dinamico
 return 0;
 //se reserva memoria en ejecucion
 //limite de tamaño: n*4
 //si se puede cambiar el tamaño en ejecucion --> con el realloc
 //si se puede liberra la memoria reservada
 //el nombre del arreglo si puede apuntar a otra direccion
}



