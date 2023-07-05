#include <stdio.h>
#include <stdlib.h>


typedef struct { //CAMPO DE BITS
    unsigned int segundo : 5 ; //lo que me queda pra los segundos
    unsigned int minuto : 6; //con 6 bits puedo represnetar 2^6 -1 = 63
    unsigned int hora : 5; //con 5 bits puedo representar 2^5 - 1 = 31

    //2^bit -1 es lo que define cuanto puedo representar
} horario;

void leerHora (horario *); //prototipo
void imprimirHora (horario);

int main()
{
    horario hour;
    leerHora (&hour);
    imprimirHora (hour);


    return 0;
}

void leerHora (horario * hour){

    int auxHora; //declaro auxiliares para la hora, min y seg
    printf("Ingrese hora: \n");
    scanf("%d", &auxHora); //leo la hora en un auxiliar porque no puedo asignar directo al csompo debits

    int auxMin;
    printf("Ingrese minutos: \n");
    scanf("%d", &auxMin);


    int auxSeg;
    printf("Ingrese segundos: \n");
    scanf("%d", &auxSeg);


    hour->hora=auxHora;
    hour->minuto= auxMin;
    hour->segundo= auxSeg;

}

void imprimirHora(horario h){
    printf("IMPRIMO LA HORA \n");
    printf("La hora es: %d \n", h.hora);
    printf("La hora es: %d \n", h.minuto);
    printf("La hora es: %d \n", h.segundo);


}


