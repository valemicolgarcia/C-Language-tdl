#include <stdio.h>
#include <stdlib.h>

int main()
{

    int vector[10]={10,20,30,40,50,60,70,80,90,100};

    int i;
    int *p= vector;


    for (i=0; i<10; i++){
        *p += 3; // es lo mismo que v[i] += 3;
    printf("vector[%d] = %d \n", i, *p); //imprimo v[i];
    //si se cambia por v[i] imprime lo mismo.
    p++; //P APUNTA A LA PROXIMA DIRECCION (avanza en el vector);
    p+=2; //se va de la direc del vector, entonce imprime cualquier cosa
    }

    //-------------------------------------------------
    return 0;

    }
