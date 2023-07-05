#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 2


typedef struct {
    char nombre [20];
    char apellido [20];
    int edad;
    int cantTitulos;
    int ranking;
}jugador;

//PROTOTIPOS
int actualizarRanking (FILE ** fb, char nombre [], char apellido [], int r, int dim);


int main()
{
    FILE *fb; //archivo binario
    fb = fopen("archJugadores", "rb+"); //archivo binario

    if (fb == NULL) {
        printf("\nError al abrir el archivo binario\n");
        return 1;
    }

    //NUEVOS DATOS A MODIFICAR EN EL ARCHIVO
    int r;
    int exito;
    char nombre [20];
    char apellido [20];
    printf ("Ingrese nombre del jugador \n");
    scanf("%s", nombre);
    while (strcmp (nombre, "ZZZ")){

        printf("Ingrese apellido del jugador \n");
        scanf("%s", apellido);
        printf("Ingrese nuevo ranking del jugador \n");
        scanf("%d", &r);
        exito = actualizarRanking (&fb, nombre, apellido, r, DIM);
    printf("Sobreescribio? respuesta : 1 (VERDADERO), 2(FALSO) \n");
    printf("La respuesta es: %d \n",exito);

    printf ("Ingrese nombre del jugador \n");
    scanf("%s", nombre);

    }

    //ARCHIVO MODIFICADO

    //imprime cualquier cosa
    fseek (fb, 0, SEEK_SET);
    jugador ju;
    fread(&ju,sizeof (jugador),1,fb);

    while(!feof(fb)){
        if (fread(&ju, sizeof(jugador),1,fb) == 1) {
            printf("%s", ju.nombre);
            printf("%s", ju.apellido);
            printf("%d", ju.edad);
            printf("%d", ju.ranking);
            printf("%d", ju.cantTitulos);
        }

    }

    return 0;
}

int actualizarRanking (FILE ** fb, char nombre [], char apellido [], int r, int dim){
int e = 0;
jugador nuevo;
    fseek (*fb, 0, SEEK_SET); //vuelvo al inicio del archivo
    nuevo.ranking = r;
    jugador v [dim]; //vector
    fread (v, sizeof (jugador), dim, *fb); //traigo el vector de jugadores desde el archivo
    int i = 0;
    while ((strcmp (v[i].nombre, nombre)) && (strcmp (v[i].apellido, apellido)) ){
        i++; //tengo la posicion del vector adentro del archivo
    }
    //si no es i es i-1
    fseek (*fb, i * sizeof(jugador), SEEK_CUR); //voy hasta el jugador que busco
    if (fwrite (&nuevo, sizeof (jugador), 1, *fb)){
        e = 1;
    }


return e;
}
