#include <stdio.h>
#include <stdlib.h>

//PUNTO 12 PRACTICA 5

typedef struct {
    int id;
    int dni;
    char apellido[20];
    char nombre[20];
    char trabajo[20];
    char correo[100];
    char ciudad[20];
    char pais[20];
} persona;

//INFORMACION DE LA LISTA
typedef struct {
    int dni;
    int desplazamiento;
} infoIndice;

//LISTA DE INFO DE PERSONAS
struct l {
    info dato; //dato
    struct l * sig;
};
typedef struct l nodo;

//PROTOTIPOS DE FUNCIONES
void inicializarLista (nodo **);
void insertarOrdenado (nodo **l, infoIndice info);

int main()
{

    // ABRO ARCHIVO DE TEXTO
    FILE *f;
    f = fopen("personas.txt", "r");

    // VERIFICACION DE APERTURA DE ARCHIVO
    if (f == NULL){
    printf ("\nError al abrir archivo fuente\n");
    return 1;
    }

    //LEO LA PRIMER LINEA --> nombres de los campos
    char campos [100];
    fgets (campos, 100, f);

    //DECLARO LISTA
    nodo * l;

    //LEO INFORMACION DE LAS PERSONAS
    persona p;
    infoIndice info;
    fscanf (fb,"%d;%d;%s;%s;%s;%s;%s;%s\n", &p.id,&p.dni, p.apellido, p.nombre, p.trabajo, p.correo, p.ciudad, p.pais);
    while (!feof (f)){
        info.dni = p.dni;
        info.desplazamiento = ftell (fb);
        insertarOrdenado(&l, info);
        fscanf (fb,"%d;%d;%s;%s;%s;%s;%s;%s\n", &p.id,&p.dni, p.apellido, p.nombre, p.trabajo, p.correo, p.ciudad, p.pais);
    }

    //ABRO ARCHIVO BINARIO
    FILE *fb;
    fb = fopen("personas2.txt", "wb");

    // VERIFICACION DE APERTURA DE ARCHIVO
    if (fb == NULL){
    printf ("\nError al abrir archivo binario :(  \n");
    return 1;
    }

    //ESCRIBO EL ENCABEZAMIENTO EN EL ARCHIVO
    char * encabezado = "DNI         DESPLAZAMIENTO";
    fwrite (encabezado, sizeof (encabezado), 1, fb);

    //ESCRIBO DATOS EN EL ARCHIVO BINARO --> INDICE
    while (l != NULL){
        fwrite (l->dato.dni, sizeof (int), 1, fb);
        fwrite (l->dato.desplazamiento, sizeof (int), 1, fb);
        l= l->sig;
    }


    //PARTE B--------------------------------
    fseek (fb, 0, SEEK_SET); //inicio del archivo
    infoIndice inf;
    nodo * indice;

    //RECORRO EL ARCHIVO Y GUARDO INDICE (lista) EN MEMORIA
    fread (&inf,sizeof (inf), 1, fb);
  //  fread (&inf.desplazamiento, sizeof (int), 1, fb);
     while (!feof (f)){
        agregarAlFinal (&indice);
        fread (&inf.dni,sizeof (int), 1, fb);
        fread (&inf.desplazamiento, sizeof (int), 1, fb);
    }

    //INGRESO LA PERSONA A BUSCAR EN EL ARCHIVO
    int dni;
    printf("Ingrese dni de la persona a buscar en el archivo \n");
    scanf ("%d", &dni);
    infoIndice ind;

    while ((indice != NULL) && (indice->dato.dni != dni)){
        indice = indice->sig;
    }
    if (indice != NULL){
        printf ("Encontro la persona en el indice! \n");
        ind.dni = dni;
        ind.desplazamiento= indice->dato.desplazamiento;
    }else{
        printf("ERROR!!!!!!!! --> la persona no existe :(    \n");
    }

    persona per;
    int exito,
    //busqueda dicotomicaaaaaaaaaaaaaaaaaaaaaa
    exito = buscar (f,ind,dni,&per);
    printf("Si exito es 1, se encontro la persona correctamente, sino es 0 \n");
    printf("EXITO: %d \n", exito);

    //IMPRIMO DATOS DE LA PERSONA ENCONTRADA
    printf(per.id);
    printf(per.dni);
    printf(per.apellido);
    printf(per.nombre);
    printf(per.trabajo);
    printf(per.correo);
    printf(per.ciudad);
    printf(per.pais);

    //CIERRE
    fclose (f);
    fclose (fb);
    free (l);

    return 0;
}

void inicializarLista (nodo ** l){ //como le mande la direccion del puntero, trabajo con puntero puntero **
    *l = NULL;
}

void insertarOrdenado (nodo **l, infoIndice info){
    nodo *ant,*act,*nue;
    ant = *l;
    act = *l;
    nuevo = malloc (1 * sizeof(nodo));
    nuevo -> dato = info;
    while (act != NULL)&&(act->dato.dni < info.dni){
        ant = act;
        act = act->sig;
    }
    if (ant = act)
        *l = nue;
    else
        ant->sig = nue;

    nue->sig = act;
}

//BUSQUEDA DICOTOMICA
int buscar (FILE* f, infoIndice indice, int dni, persona * p){


//????????????????????????????????


}











