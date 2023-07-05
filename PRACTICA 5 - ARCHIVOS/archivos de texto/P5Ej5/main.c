#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    /*Escriba un programa que permita a un usuario consultar si un conjunto de palabras existe o no en
    un diccionario. El usuario ingresa de a una palabra y la consulta finaliza cuando ingresa la palabra
    “ZZZ”.

    Para cada palabra ingresada se debe informar si la misma pertenece o no al diccionario.

    El diccionario consiste en un archivo de texto y las palabras se encuentran ordenadas en forma
    ascendente (una por línea). Se desea generar una estructura de datos dinámica (memoria RAM) en
    la cual se almacenen las palabras de todo el diccionario. Luego, verifique la pertenencia de las
    palabras ingresadas por el usuario utilizando dicha estructura en lugar del archivo.
*/

struct l {
    char dato [15]; //dato
    struct l * sig;
};

typedef struct l nodo; // nodo de la lista ----> uso: *nodo (puntero) / **nodo (contenido)

//PROTOTIPOS
void inicializarLista (nodo **); //--> modifico contenido
void agregarInicio (nodo **, char * dato);
void imprimir (nodo *);

int main()
{
    //PROCESAMIENTO DE LA LISTA!!!--------------------------------------------
    nodo * l;
    inicializarLista(&l);
    char fin []= "ZZZ";
    char cadena [15];

    scanf ("%s", cadena);
    while ((strcmp (cadena,fin))){
//            cadena[strlen(cadena)]='\n';
//             cadena[strlen(cadena)]='\0';
        agregarInicio(&l, cadena);
        scanf ("%s", cadena);
    }
    printf("\n");
    printf("Imprimo palabras que voy a analizar \n");
    imprimir(l);
    printf("\n");

    //PROCESAMIENTO DEL ARCHIVO-------------------------------------------
    char linea [15]; //palabra leida
    char palabra [15];
    FILE *f;
    f = fopen("diccionario.txt", "r");

    //verifico errores
    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
     return 1; }

    nodo * aux;
    aux= l;
    int booleano;

    while (aux != NULL){
        fseek (f,0, SEEK_SET); //INICIO
        strcpy (palabra, aux->dato);
        printf("La palabra a analizar es: %s \n", palabra);
        fscanf (f, "%s", linea);
        booleano = (strcmp(linea,palabra));

        while ( (!feof (f)) && (booleano) ){
            //printf("Linea leida: %s", linea);
            fscanf (f, "%s", linea);
            booleano = (strcmp(linea,palabra));
            }

        //IMPRIMO RESULTADO!
        if (!(booleano))
            printf ("Esta palabra pertenece al diccionario!!! \n");
        else
            printf("Esta palabra no pertenece al diccionario :( \n");
        //--------------------

        aux=aux ->sig;
    }

    fclose (f);


    return 0;
}

//INICIALIZA LISTA
void inicializarLista (nodo ** l){ //como le mande la direccion del puntero, trabajo con puntero puntero **
    *l = NULL;
}

//AGREGA AL INICIO
void agregarInicio (nodo ** l, char * dato){
    printf("agrega al inicio el datoooo \n");
    nodo * nue;
    nue = (nodo*) malloc (1* sizeof (nodo)); // new (nue)
    strcpy(nue->dato, dato);
    nue -> sig = *l; //nue^sig = l
    *l = nue; //l= nue, cambio el puntero
}

//IMPRIMIR LISTA
void imprimir (nodo * l){
    printf("Imprimo lista: \n");
    while (l!= NULL){
        printf("%s , ", l->dato);
        l = l -> sig;
    }
    printf("\n");
}
