#include <stdio.h>
#include <stdlib.h>

typedef enum  {vibrar=1, linterna, trasera, frontal, datos, GPS, wifi, bluetooth} pos; //aca manejo la pos a la que tego que correr

typedef struct {
    unsigned int vibrar : 1; // 0 o 1
    unsigned int linterna : 1;
    unsigned int trasera : 1;
    unsigned int frontal : 1;
    unsigned int datos : 1;
    unsigned int gps : 1;
    unsigned int wifi : 1;
    unsigned int bluetooth : 1;
} modulos;

//PROTOTIPOS!!!
void prender(modulos *, unsigned int);
void apagar(modulos *, unsigned int);
void invertir (modulos * c, unsigned int pos);
void estaActivo (modulos c, unsigned int pos);
void imprimir(modulos);

int main() {
    modulos celular  = {0,0,0,0,0,0,0,0}; //prendo todos los modulos del celular 00000000

    printf("prendo vibrar \n");
    prender(&celular, vibrar); //prendo trasera que es pos 3 00100000
    imprimir(celular);

    printf("apago vibrar \n");
    apagar (&celular, vibrar); //apago en la pos 8 00100000
    imprimir(celular);

    printf("invierto vibrar \n");
    invertir(&celular, vibrar);
    imprimir(celular);

    printf("Esta activo el vibrar? \n");
    estaActivo(celular, vibrar);
    imprimir(celular);

    return 0;
}
//-------------PRENDER----------------------------------------
void prender(modulos * c, unsigned int pos) {
    unsigned int *byte = (unsigned int *) c; //aca ya tengo la direccion de c,
    //porque si quisiera lo que contiene c tengo que trabajar con &
    unsigned int masc = (1<<(8-pos)); //00000000 //lo corro para la izquierda
    *byte |= masc; //hago el or con la mascara
}

//--------------APAGAR----------------------------------------
void apagar (modulos * c, unsigned int pos) {
    unsigned int *byte = (unsigned int *) c; //aca ya tengo la direccion de c,
    //porque si quisiera lo que contiene c tengo que trabajar con &
    unsigned int masc = (1<<(8-pos)); //00000000 //lo corro para la izquierda
    *byte &= (~masc); //hago el or con la mascara
}

//--------------INVERTIR----------------------------------------
void invertir (modulos * c, unsigned int pos) {
    unsigned int *byte = (unsigned int *) c; //aca ya tengo la direccion de c,
    //porque si quisiera lo que contiene c tengo que trabajar con &
    unsigned int masc = (1<<(8-pos)); //00000000 //lo corro para la izquierda
    *byte ^= (masc); //hago el or con la mascara
}

//--------------ESTA ACTIVO----------------------------------------
void estaActivo (modulos c, unsigned int pos) {
    unsigned int byte = *(unsigned int *) &c; //aca ya tengo la direccion de c,
    //porque si quisiera lo que contiene c tengo que trabajar con &
    unsigned int masc = (1<<(8-pos)); //00000000 //lo corro para la izquierda
    if (byte & masc)
        printf("El modulo esta activo \n");
    else
        printf("El modulo esta apagado \n");
}

//-------------IMPRIMIR-----------------------------------
void imprimir (modulos c) {
     //IMPRIMO EL CELULAR!!!!
    unsigned int byte = *(unsigned int *) &c;
    //primero se toma la direccion de la estructura celular y
    //se la castea a un entero sin signo para poder represenar
    //todos los campos de la estructura como un unico entero sin signo
    printf("Estado del celular: %d \n ", byte); //imprimo el byte, q es el celular en entero sin signo
}
