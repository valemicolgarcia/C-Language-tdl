#include <stdio.h>
#include <stdlib.h>

/*Escriba un programa que calcule e imprima el promedio de 4 números que se
 pasan como argumentos a la función main. En caso de no pasar la
cantidad necesaria de parámetros, informar al usuario.
*/

int main (int argc, char * argv[]) {

      int i;
      int suma = 0;
      if (argc < 4)
            printf( "No se pasaron la cantidad necearia de parametros \n");
      else{
        for (i=1;i<argc;i++){
        printf("argv[%d] -> %s \n", i, argv[i]);// PARAMETROS DE LA FUNCION
        suma = suma + atoi(argv[i]);
       }

       printf("La suma de %d \n", suma );
        printf("ARGC %d \n", argc);
          float promedio = (float) suma / (argc-1);
          printf("El promedio es: %f", promedio);
      }

    return 0;
    }
