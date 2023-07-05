#include <stdio.h>
#include <stdlib.h>

/*Defina la estructura de una lista enlazada de enteros. Implemente las siguientes funciones:
a. Inicializar la lista.
b. Eliminar todos los elementos de la lista.
c. Agregar un elemento al principio de la lista.
d. Agregar un elemento al final de la lista.
e. Calcular la cantidad de elementos de la lista.
f. Imprimir todos los elementos separados por coma.
*/


struct l {
    int dato; //dato
    struct l * sig;
};
typedef struct l nodo; // nodo de la lista ----> uso: *nodo (puntero) / **nodo (contenido)

//typedef nodo * lista; //puntero a la lista ----> uso lista (puntero) / *lista (contenido)

void inicializarLista (nodo **); //--> modifico contenido
void eliminarLista (nodo **);
void agregarInicio (nodo **, int dato);
void agregarFinal (nodo **, int dato);
int cantidad (nodo *);
void imprimir (nodo *);


int main()
{
    nodo * l; //puntero a lista
    int num;
    inicializarLista(&l); //le mando la direccion del puntero a lista
    printf("Ingrese un numero para agregar a la lista: (INICIO) \n");
    scanf("%d", &num);
    agregarInicio(&l, num);
    imprimir(l);
    agregarFinal(&l, 2);
    agregarFinal(&l, 3);
    agregarFinal(&l, 4);
    printf("Ingrese un numero para agregar a la lista: (FINAL) \n");
    scanf("%d", &num);
    agregarFinal(&l, num);
    imprimir(l);
    printf("\n");
    int cant;
    cant = cantidad(l);
    printf("La cantidad de elementos de la lista es: %d \n", cant);
    printf("\n");
    printf("Elimino toda la lista \n");
    eliminarLista(&l);
    imprimir(l);




    return 0;
}

void inicializarLista (nodo ** l){ //como le mande la direccion del puntero, trabajo con puntero puntero **
    *l = NULL;
}

void eliminarLista(nodo ** l){ //elimino el contenido
    nodo * aux;
    while (*l != NULL ){
        aux = *l; //aux = l
        *l = (*l)->sig; //l = l^sig
        free(aux); //dispose (aux)
    }
}

void agregarInicio (nodo ** l, int dato){
    nodo * nue;
    nue = (nodo*) malloc (1* sizeof (nodo)); // new (nue)
    nue -> dato = dato; // nue^dato = dato
    nue -> sig = *l; //nue^sig = l
    *l = nue; //l= nue, cambio el puntero
}

void agregarFinal (nodo ** l, int dato){

    //CREO EL DATO
    nodo * nue;
    nue = (nodo*) malloc (1* sizeof (nodo));
    nue -> sig = NULL;
    nue -> dato = dato;

    //RECORRO EL AUXILIAR
    nodo * aux; //aux para no perder el puntero a la lista
    aux = *l; //aux = l
    while (aux->sig != NULL) //while (l != nill)
        aux = aux -> sig; //aux = aux^sig;

    //AGREGO A LISTA
    aux -> sig = nue; //aux^sig = nue
}

int cantidad (nodo * l){
    int cant = 0;
    while (l != NULL){
        cant++;
        l = l -> sig;
    }
    return cant;
}

void imprimir (nodo * l){
    printf("Imprimo lista: \n");
    while (l!= NULL){
        printf("%d , ", l->dato);
        l = l -> sig;
    }
    printf("\n");
}







