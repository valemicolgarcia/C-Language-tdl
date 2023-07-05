#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

    struct l{
        char dato [15];
        struct l * sig;
    };
    typedef struct l nodo;

    nodo* inicializarDic ();



    /*
    a) Crear un diccionario: inicializa la estructura del diccionario.
    b) Agregar palabra: agrega una nueva palabra al diccionario siempre y cuando no exista. Retorna si
    la agregó o no.
    c) Existe palabra: determina si una palabra está en el diccionario o no.
    d) Eliminar palabra: elimina una palabra del diccionario. Retorna si la palabra fue eliminada o no.
    e) Cargar desde un archivo: carga un diccionario desde un archivo de texto.
    f) Guardar a un archivo: guarda un diccionario en un archivo de texto.
    g) Destruir el diccionario: libera los recursos del diccionario.
    */



#endif // DICCIONARIO_H_INCLUDED
