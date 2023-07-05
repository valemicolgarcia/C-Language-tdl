#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct carta {
    int num;
    char palo [20];
};
typedef struct carta cart;

//PROTOTIPOS----------------------------------------------------------------------
void inicializarMazo (cart [], int); //parametro por referencia
void analisisRepetido (int * , int [], int);
void barajarMazo (cart [], int); //parametro por referencia
cart sacarCarta (cart [], int *); //parametros por referencia
void imprimirCarta (cart);
void imprimirMazo (cart[], int);

//-----------------------------------------------------------------------------------
int main()
{
    srand(time(NULL)); //voy a usar el random
    int dimension = 4; //no lo hice con define para despues modificarlo
    cart mazo [dimension]; //vector de 50 elementos tipo carta
    inicializarMazo(mazo, dimension);
   // imprimirMazo(mazo, dimension);
    barajarMazo (mazo, dimension); //tengo que mezclar el mazo de cartas en un orden aleatorio
    imprimirMazo(mazo, dimension);
    printf ("La dimension en un principio es: %d \n",dimension);
    cart cartaSacada;
    cartaSacada = sacarCarta (mazo, &dimension); //la dimension se va a modificar entonces le mando el puntero
    printf ("La dimension finaliza siendo: %d \n",dimension);
    printf("Imprimo la carta sacada: \n");
    imprimirCarta (cartaSacada);
    printf("\n");
    printf("Nuevamente: \n");

    imprimirMazo(mazo, dimension);

    return 0;
}
//FUNCIONES ---------------------------------------------------------

void inicializarMazo (cart mazo [], int cant){
    //ARREGLAR PQ 0 EFICIENCIA!!
    int n = cant/4;

    for (int i=0; i<n; i++){
         mazo[i].num = i+1; // le sumo 1 porque no quiero carta 0
         strcpy(mazo[i].palo, "ORO");
    }
    for (int i=n; i<(n*2); i++){
         mazo[i].num = i+1; // le sumo 1 porque no quiero carta 0
         strcpy(mazo[i].palo, "COPA");
    }
    for (int i=(n*2); i<(n*3); i++){
         mazo[i].num = i+1; // le sumo 1 porque no quiero carta 0
         strcpy(mazo[i].palo, "BASTO");
    }
    for (int i=(n*3); i<(n*4); i++){
         mazo[i].num = i+1; // le sumo 1 porque no quiero carta 0
         strcpy(mazo[i].palo, "ESPADA");
    }
}

void imprimirCarta (cart cartaa){
    printf("El numero de la carta es: %d \n", cartaa.num);
    printf("El palo de la carta es: %s \n", cartaa.palo);
}
void imprimirMazo (cart mazo[], int dim){
    printf("Imprimo mazo de cartas: \n");
    for (int i=0; i<dim; i++){
        imprimirCarta(mazo[i]);
    }
    printf("\n");

}
//----------------------------------------------------------------
void analisisRepetido (int * numX , int vector [], int dim){
    //veo si el numero que salio en el random esta repetido. si es asi lo cambio.
    int booleano = 0;
    for (int j=0;j<dim;j++){//recorro vector de numeros aleatorios
                if ( (vector[j]) == (*numX)){ //si esta repetido booleano es 1
                   booleano = 1;
                   break;
                }
            }
    while (booleano == 1){ //mientras haya repetido
            *numX= rand()%dim; //quiero una posicion random menor a la dimension del vector
            booleano = 0;
            for (int j=0;j<dim;j++){//recorro vector de numeros aleatorios
                if ((vector[j]) == (*numX)){
                   booleano = 1;
                   break;
                }
            }
        }
}
//-------------------------------------------------------------------------------
void barajarMazo (cart mazo[], int dim ){
//tengo que mezclar todas las cartas en orden aleatorio
int vector [dim];
for (int i=0;i<dim;i++){ //inicializo vector para no tener complicaciones
    vector[i]= -1;
}
int numX;
cart aux;
for (int i=0; i<dim; i++){
   numX= rand()%dim; //quiero una posicion random menor a la dimension del vector
   analisisRepetido (&numX, vector, dim);
   vector [i]= numX;
   //la cantidad de cartas que cambio es indistinta a la cantidad de cartas que hay, no es necesario hacer el analisis repetido
   //porque no se repiten si hago swap.
   aux = mazo[i]; //
   mazo [i] = mazo [numX];  //intercambio los valores
   mazo [numX] = aux;
}
}

cart sacarCarta (cart mazo [], int * dim){
    //tengo que agarrar una carta cualquier del mazo y eliminarla
    int numX = rand()% (*dim);
    cart cartaSacada = mazo[numX]; //carta a devolver

    //ELIMINO: los elementos hay que correrlos de lugar si saco la carta, lo que hago es pisar la carta
    for (int i=numX; i<(*dim); i++){
        mazo[i] = mazo [i+1]; //los corro de lugar
    }
    //la dimension del vector va a ser menor
    (*dim)--;
    return cartaSacada;
}



