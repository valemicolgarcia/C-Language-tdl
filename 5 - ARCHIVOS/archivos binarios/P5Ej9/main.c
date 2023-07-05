

    /*Escriba un programa que lea información de 20 jugadores de tenis. De cada jugador se lee nombre y
    apellido, edad, cantidad de títulos, ranking actual y fortuna acumulada. Defina una estructura de
    datos adecuada para la información y almacene la misma en un archivo binario. Finalizada la
    lectura, procese los datos almacenados en el archivo e informe:
    a) Nombre y apellido del jugador con mejor ranking.
    b) Nombre y apellido del jugador que más títulos ha ganado.
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 2


typedef struct {
    char nombre [20];
    char apellido [20];
    int edad;
    int cantTitulos;
    int ranking;
}jugador;

//PROTOTIPOS
void lecturaInfo (jugador v[]);
void almacenamientoArchivo (FILE ** fb, jugador v [], int dimL);
void procesamientoDatos (FILE * fb, int dim);

//MAIN
int main()
{
    FILE *fb; //archivo binario
    fb = fopen("archJugadores", "wb+"); //archivo binario

     if (fb == NULL) {
        printf("\nError al abrir el archivo binario\n");
        return 1;
    }

    jugador v [3];
    lecturaInfo(v);
    almacenamientoArchivo (&fb,v,DIM);

    fseek (fb, 0, SEEK_SET); //vuelvo al inicio del archivo
    procesamientoDatos (fb, DIM);


    return 0;
}

void lecturaInfo (jugador v[]){ //LECTURA DE LA INFORMACION
    int i;
    for (i=0; i<DIM;i++){
        printf("Ingrese nombre del jugador \n");
        scanf ("%s", v[i].nombre);
        printf("Ingrese apellido del jugador \n");
        scanf ("%s", v[i].apellido);
        printf("Ingrese edad del jugador \n");
        scanf ("%d", &(v[i].edad));
        printf("Ingrese cantidad de titulos del jugador \n");
        scanf ("%d", &(v[i].cantTitulos));
        printf("Ingrese ranking del jugador \n");
        scanf ("%d", &(v[i].ranking));
    }
}

void almacenamientoArchivo (FILE ** fb, jugador v [], int dimL){

    //ALMACENAMIENTO EN ARCHIVO BINARIO

    fwrite (v, sizeof (jugador), dimL, *fb);

    /*char * frase;
    frase = "INFORMACION DEL JUGADOR: ";
    int i;
    for (i=0;i<DIM;i++){
        fwrite (frase, sizeof (char *), 1, *fb);
        fwrite (v[i].nombre, sizeof(v[i].nombre), 1, *fb);
        fwrite (v[i].apellido, sizeof(v[i].apellido), 1, *fb);
        fwrite (&(v[i].edad), sizeof(int), 1, *fb);
        fwrite (&(v[i].cantTitulos), sizeof(int), 1, *fb);
        fwrite (&(v[i].ranking), sizeof(int), 1, *fb);
    }*/
}

void procesamientoDatos (FILE * fb, int dim){

    jugador j1; // + ranking
    j1.ranking = 9999;
    jugador j2; // + titulos
    j2.cantTitulos = -1;

    jugador aux;
    fread (&aux, sizeof (jugador),1,fb);
    while (!feof (fb) ){
        if (aux.ranking < j1.ranking)
            j1 = aux;
        if (aux.cantTitulos > j2.cantTitulos)
            j2 = aux;
        fread (&aux, sizeof (jugador),1,fb);
    }

    //INFORMO NOMBRE Y APELLIDO
    printf("El nombre del jugador con mejor ranking es: %s \n", j1.nombre);
    printf("El apellido del jugador con mejor ranking es: %s \n", j1.apellido);

    printf("El nombre del jugador con mas titulos es:  %s \n", j2.nombre);
    printf("El apellido del jugador con mas titulos es: %s \n", j1.apellido);

}





