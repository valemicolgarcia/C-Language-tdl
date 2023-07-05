#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CONST 5


//------ PROTOTIPOS ------
void cargarVector(int[], int);
void imprimirVector(int [], int);
void swap (int *, int);
void swapCambio (int *, int *);


//---------MAIN---------
int main()
{
    srand(time(NULL));

    int vector [CONST];

    cargarVector(vector, CONST);
    imprimirVector(vector, CONST);
    swap (vector, CONST);
    imprimirVector(vector, CONST);
    printf(" \n");
    return 0;
}

//---------MÉTODOS---------

void cargarVector (int vector [],int cant){ // le mando la dimF asi me sirve para todos los vectores
    int i;
    for (i = 0; i < cant; i++)
        vector[i] = rand() % 51;
}

void imprimirVector(int vector [], int cant){
    int i;
    for (i = 0; i < cant; i++)
            printf(" %d -", vector[i]);
    printf("\n");
}

void swapCambio(int * pri, int * ult){
int aux;
aux = *ult;
*ult = *pri;
*pri= aux;

}

void swap (int * vector, int cant){
int i;
for (i=0; i<cant/2; i++){

    swapCambio (&vector[i], &(vector[cant-1]));
   // aux= vector[i];
   // vector [i] = vector [cant-1];
  //  vector [cant-1]= aux;
    cant--;
}


}
