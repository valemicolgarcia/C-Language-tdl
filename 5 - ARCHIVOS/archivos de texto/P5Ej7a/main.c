#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *f, *copia; //f--> archivo del que voy a copiar el contenido
    f = fopen("Ejercicio7a.txt", "r");
    copia = fopen("Copia.txt", "w");

    if (f == NULL) {
        printf("\nError al abrir el archivo\n");
        return 1;
    }

    char c;
    c = fgetc(f);
    while(!feof(f)){
       fputc(c,copia);
       c = fgetc(f);
    }
    return 0;
}
