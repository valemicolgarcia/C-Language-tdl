#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

    // Retorna una nueva pila. Se debe invocar antes de manipular cualquiera de ellas.
    Stack s_create () { //reservo espacio en memoria para la PILA

        Stack s;
        s.tope = NULL;
        s.tamanio = 0;

        return s;
    }

    // Apila n en s. Retorna el elemento apilado.
   int s_push(Stack* s, int n){ //reservo espacio para el nodo
        Nodo * nod = (Nodo*) malloc (1*sizeof (Nodo));
        nod -> dato = n;
        nod -> ptr = s->tope; //el nodo apunta hacia el tope de la pila
        s-> tope = nod; // el tope de la pila lo subo al nuevo nodo
        s->tamanio ++;
        return n;
   }

    // Desapila un elemento de s.
    int s_pop (Stack* s){
        //me guardo el dato, en un aux que va a ser el puntero para enganchar el sp
        int dato = s->tope->dato; //agarrp el tope de la pila, y de ahi el dato que voy a desapilar
        Nodo *aux = s->tope; //me guardo el puntero al primer elemento
        s->tope = s->tope->ptr ; //avanzo en el puntero de la pila para eliminar
        free (aux); //libero la memoria de aux
        s->tamanio --;
        return dato;
    }

    // Retorna el próximo elemento que será desapilado.
    int s_top (Stack s) {
        if (s.tope == NULL) //analizo si esta vacia la pila!!!!
            return -1;
        int dato = s.tope->dato;
    return dato;
    }

    // Retorna 1 si s está vacía, 0 en caso contrario.
    int s_empty(Stack s) {
        if (s.tope == NULL)
            return 1;
        else
            return 0;
        }

    // Retorna la cantidad de elementos apilados en s.
    int s_length(Stack s) {
        int cant;
        cant = s.tamanio;
        return cant;
        }

