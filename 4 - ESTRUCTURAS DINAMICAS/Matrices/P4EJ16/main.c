#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//ESTRUCTURA DE LA LISTA
struct l {
    int dato; //dato
    struct l * sig;
};
typedef struct l nodo; // nodo de la lista ----> uso: *nodo (puntero) / **nodo (contenido)


void inicializarLista (nodo **); //--> modifico contenido
void agregarInicio (nodo **, int dato);
void imprimir (nodo *);


int main()
{

    nodo * l;
    inicializarLista(&l);
    int n;
    printf("Ingrese un numero entero \n");
    scanf ("%d", &n);

    int limite = floor(sqrt(n)); //redondea para abajo
    int result;
    int i;
    for (i=1; i<=limite; i++){
        if (!(n%i)){
               agregarInicio(&l,i);
               result = (n/i);
               if (i != result)
                agregarInicio(&l,result);
        }
    }

    imprimir (l);

    return 0;
}

void inicializarLista (nodo ** l){ //como le mande la direccion del puntero, trabajo con puntero puntero **
    *l = NULL;
}

void agregarInicio (nodo ** l, int dato){
    nodo * nue;
    nue = (nodo*) malloc (1* sizeof (nodo)); // new (nue)
    nue -> dato = dato; // nue^dato = dato
    nue -> sig = *l; //nue^sig = l
    *l = nue; //l= nue, cambio el puntero
}

void imprimir (nodo * l){
    printf("Imprimo lista: \n");
    while (l!= NULL){
        printf("%d , ", l->dato);
        l = l -> sig;
    }
    printf("\n");
}
