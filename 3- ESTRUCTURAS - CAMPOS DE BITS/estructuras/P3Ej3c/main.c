#include <stdio.h>
#include <stdlib.h>
#define DIM 4


//---------------------------------- inciso c----------------------------------------------

struct pun3D{ //representa una posicion en el espacio
    float x;
    float y;
    float z;
};
typedef struct pun3D punto3D; //struct punt3D lo redefino a --> punto3D (TIPO DE DATO)

//------------------------------------------------------------------------------------------
int main()
{

    punto3D v[DIM];
   // punto3D p;
    printf("El tamaño de la estructura es %u bytes \n" , (unsigned int)sizeof(struct pun3D));
    printf("El tamaño de la estructura con typedef es %u bytes \n" , (unsigned int)sizeof(punto3D));
    printf("El tamaño del vector es %u bytes \n" , (unsigned int)sizeof(v));

    //preguntar por el unsigned int pq lo saque de chat gpt

    return 0;
}
