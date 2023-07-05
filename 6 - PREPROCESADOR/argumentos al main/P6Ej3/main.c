#include <stdio.h>
#include <stdlib.h>

    /*a. Investigue las funciones de conversión de texto a número y escriba un programa “calculadora.c” que
    reciba dos números enteros y un operador como argumentos a la función main e imprima en pantalla el
    resultado de la operación. El operador debe ser: “+”, “-”, “/”, “.”. Si el operador recibido no es uno de los
    mencionados anteriormente, entonces el programa debe imprimir un mensaje de error.

    b. Utilice una terminal para compilar el programa a través de la línea de comandos.

*/

    int main (int argc, char * argv[]) {


            printf ("Nro entero  %d \n", atoi (argv[1]));
            printf ("Nro entero %d \n", atoi(argv[2]));
            printf ("OPERADOR %s \n", argv[3]);

            switch (argv[3][0]){
                case '+' : printf (" La suma es: %d \n ", (atoi(argv [2]) + atoi(argv [1])) );
                break;
                case '-' : printf (" La resta es: %d \n ", (atoi (argv [2]) - atoi (argv [1])) );
                break;
                case '*' : printf (" El producto es: %d \n ",(atoi(argv [2]) * atoi (argv [1])) );
                break;
                case '/' : printf (" La division es: %f \n ",(float)atoi (argv [2]) / atoi(argv [1]));
                break;

                default: printf("ERROR \n");
            }
            //la multiplicacion por compilador tengo que llamarla con \*




        return 0;
        }
