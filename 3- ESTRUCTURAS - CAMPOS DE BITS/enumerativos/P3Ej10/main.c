#include <stdio.h>
#include <stdlib.h>

typedef enum  {vibrar = 1, linterna = 2, trasera = 4, frontal = 8, datos = 16, GPS = 32, wifi = 64, bluetooth = 128} bits;

const bits todosApagados = 0x00;
const bits todosPrendidos= 0xFF;
//prototipo
void prender (bits *, int);
void apagar (bits *, int);
void invertir (bits *, int);
void estaActivo (bits , int);

int main()
{
    bits celular = todosApagados; //un celular lo apago --> a la que le asigno 00000000 //INICIALIZO
    prender(&celular, bluetooth);
    apagar (&celular, bluetooth);

    printf("Prendo todos \n");
    celular = todosPrendidos;

    invertir (&celular, bluetooth);
    printf("%d \n", celular);
    estaActivo (celular, bluetooth);
    // celular = todosPrendidos; //prendo todos los bits --> una variable a la que le asigno 11111111
    return 0;
}

void prender (bits * celular, int modulo){
    *celular |= modulo; //asi prendo el bluetooh 00000000 or 00000001
    printf("Prende: %d \n" , * celular);
}

void apagar (bits * celular, int modulo){
    *celular &= ~modulo; //asi prendo el bluetooh 00000000 or 00000001
    printf("Apaga: %d \n" , * celular);
}

void invertir (bits * celular, int modulo){
    *celular ^= modulo; //asi prendo el bluetooh 00000000 or 00000001
    printf("Invierte: %d \n" , * celular);
}
void estaActivo (bits celular, int modulo){
    if ((celular & modulo))
        //1010 and 1000 = 1000 -- todo lo que es diferente de 0 es verdadero
        printf("ESTA PRENDIDO EL MODULO");
    else
        printf("ESTA APAGADO");

}

