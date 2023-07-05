#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIMF 5
#define DEBUG


        /*Realice un programa que genere un vector de 1000 enteros al azar y utilice una función para localizar un
    elemento. Se pide:

    a) Implementar la función de búsqueda que, dado un entero, retorne la posición donde se encuentra.
    En caso de no existir el número retorne -1.

    b) Modificar a) para agregar información de depuración que permita imprimir en consola la cantidad
    de veces que se debió acceder al arreglo para encontrar (o no) el elemento en cada llamado a la
    función. Utilice las directivas del procesador para activar/desactivar la depuración e imprimir/no
    imprimir la información en la consola.

    c) Verifique el tamaño del programa compilando con la depuración y sin la depuración. Explique
    porque difieren.
    */

//PROTOTIPOS
void cargarVector(int [], int);
void imprimirVector(int [], int);
int buscarPosicion(int [], int, int);

int main()
{
    srand(time(NULL));
    int array [10];
    int i;
    for (i=0; i<10;i++){
        array [i] = rand() % 10;
    }
    imprimirVector(array, DIMF);
    int x;
    int num;
    printf ("Ingrese numero a buscar en el vector: \n");
    scanf ("%d", &num);
    x = buscarPosicion(array, DIMF, num);
    printf ("La posicion del numero en el vector es: %d", x+1);


    //Falta inciso de verifique el tamano del programa. preguntar como se hace

    return 0;
}


void cargarVector(int v[], int cant) {
    int i;
    for (i = 0; i < cant; i++)
        v[i] = rand() % 21;
}

void imprimirVector(int v[], int cant) {
    printf("Imprime vector: \n");
    int i;
    for (i = 0; i < cant; i++)
        printf("%d ", v[i]);
}

int buscarPosicion(int v[], int cant, int num) {
    int i;
    for (i = 0; i < cant ; i++){
        if (v[i] == num) {
            break;
        }
    }
    #ifdef DEBUG
        printf("Se accedio %d veces \n", i == cant ? cant : i+1); // si defino dbug entra aca.
    #endif // DEBUG

    return (i == cant ? -1 : i); //si no lo encuentra retorna -1
}
