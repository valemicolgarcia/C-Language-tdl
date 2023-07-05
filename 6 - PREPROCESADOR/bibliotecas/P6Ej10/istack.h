#ifndef ISTACK_H_INCLUDED
#define ISTACK_H_INCLUDED

    struct nodo { //lista
        int dato;
        struct nodo *ptr;
        };
    typedef struct nodo Nodo;

    struct stack {
        Nodo *tope;
        int tamanio;
    };
    typedef struct stack Stack;

    //PROTOTIPOS DE LAS FUNCIONES DR LA PILA

    Stack s_create (); // Retorna una nueva pila. Se debe invocar antes de manipular cualquiera de ellas.
    int s_push(Stack* s, int n); // Apila n en s. Retorna el elemento apilado.
    int s_pop (Stack* s); // Desapila un elemento de s.
    int s_top (Stack s); // Retorna el próximo elemento que será desapilado.
    int s_empty(Stack s); // Retorna 1 si s está vacía, 0 en caso contrario.
    int s_length(Stack s); // Retorna la cantidad de elementos apilados en s.



#endif // ISTACK_H_INCLUDED
