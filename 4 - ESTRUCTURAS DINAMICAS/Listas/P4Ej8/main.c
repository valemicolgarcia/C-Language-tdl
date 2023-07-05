#include <stdio.h>
#include <stdlib.h>

/*Utilizando la estructura y funciones de los ejercicios anteriores escriba un programa que lea números
enteros desde teclado hasta ingresar el número 0. Luego, vuelva a leer otro número entero desde
teclado y elimine de la lista a todos aquellos que sean múltiplos del mismo.
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
void eliminarElemento(nodo ** , int);


int main()
{
    nodo * l; //puntero a lista
    int num;
    inicializarLista(&l); //le mando la direccion del puntero a lista

    printf("Ingrese un numero para agregar a la lista: \n");
    scanf("%d", &num);

    while (num != 0){
        agregarFinal(&l, num);
        printf("Ingrese un numero para agregar a la lista: \n");
        scanf("%d", &num);
    }
    imprimir(l);
    printf("\n");

    printf("Ingrese numero para borrar sus multiplos \n");
    scanf("%d", &num);
    eliminarElemento(&l,num);
    imprimir(l);


    //LIBERO LA MEMORIA DE LA LISTA
    free (l);
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
    if (*l == NULL)
        *l = nue;
    else {
        while (aux->sig != NULL) //while (l != nill)
        aux = aux -> sig; //aux = aux^sig;
    //AGREGO A LISTA
    aux -> sig = nue; //aux^sig = nue
    }

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

void eliminarElemento(nodo ** l, int num){ //elimino el contenido
    nodo * aux;
    nodo * ant;
    nodo *act;
    aux = *l;
    ant = NULL;
    act = *l;

    while ((act) != NULL ){
        if (!((act)->dato % num)){
            if ((ant)== NULL)
                (*l) = (*l)->sig;
            else{
                (ant)->sig = (act)->sig;
            }
            aux = act;
            (act) = (act)->sig;
            free (aux);
        }
        else{
            ant=(act);
            act=(act)->sig;
        }
    }
}

