#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define JUGADORES 3

typedef struct {
    char nombre[20];
    char apellido[20];
    unsigned int edad;
    unsigned int cantTitulos;
    unsigned int ranking;
    int fortune;
} Jugador;

void leerYGuardar(FILE **bf, int cant);

void informarDatos(FILE **f, int cant);


//En el archivo voy a tener char, unsigned, unsigned, unsigned, int
int main()
{
    FILE *bf = fopen("data", "wb");
    if (bf == NULL) {
        printf("Hubo un error al crear el archivo binario");
        return 1;
    }

    leerYGuardar(&bf, JUGADORES);

    fclose(bf);

    FILE *barch = fopen("data", "rb");
    if (barch == NULL) {
        printf("Hubo un error al abrir el archivo binario");
        return 1;
    }

    informarDatos(&bf, JUGADORES);

    fclose(barch);

    return 0;
}



void leerYGuardar(FILE **bf, int cant){
    Jugador j;
    int i;

    for(i=0; i<cant; i++) {
        printf("Nombre: ");
        scanf("%s", j.nombre);
        printf("Apellido: ");
        scanf("%s", j.apellido);
        printf("Edad: ");
        scanf("%u", &j.edad);
        printf("Cantidad de Titulos: ");
        scanf("%u", &j.cantTitulos);
        printf("Ranking actual: ");
        scanf("%u", &j.ranking);
        printf("Fortuna acumulada: ");
        scanf("%d", &j.fortune);
        fwrite(&j, sizeof(Jugador), 1, *bf);
    }
    printf("Successful reading \n");
}


void informarDatos(FILE **f, int cant) {
    Jugador bestRank;
    Jugador maxTitulos;
    bestRank.ranking = 999999;
    maxTitulos.cantTitulos = 0;
    Jugador j;
    int i;
    for (i = 0; i < cant; i++) {
        fread(&j, sizeof(Jugador), 1, *f);
        if (bestRank.ranking > j.ranking) {
            bestRank = j;
        }
        if (maxTitulos.cantTitulos < j.cantTitulos) {
            maxTitulos = j;
        }
    }
    printf("El jugador con mejor ranking es: %s %s \n", bestRank.nombre, bestRank.apellido);
    printf("EL jugador con mas titulos es: %s %s \n", maxTitulos.nombre, maxTitulos.apellido);
}
