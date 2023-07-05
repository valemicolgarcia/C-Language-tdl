#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fb = fopen("archJugadores", "rb");
    if (fb == NULL) {
        printf("No se pudo abrir el archivo binario");
        return 1;
    }

    //Voy al final del archivo
    fseek(fb, 0, SEEK_END);
    //Imprimo tamaño
    printf("El tamanio del archivo es: %ld", ftell(fb));

    fclose(fb);

    return 0;

}
