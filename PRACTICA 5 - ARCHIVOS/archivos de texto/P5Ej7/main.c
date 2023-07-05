#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f, *copia; //f--> archivo del que voy a copiar el contenido

    //ABRO EL ARCHIVO
    f = fopen("Ejercicio7b.txt", "r");
    copia = fopen("Copiab.txt", "w");

    //VERIFICO ERRORES
    if (f == NULL) {
        printf("\nError al abrir el archivo\n");
        return 1;
    }
    //COPIA CON FGETS
    char linea [100];
    fgets(linea,100,f);
    while(!feof(f)){
        fputs(linea,copia);
        printf("%s", linea);
        fgets(linea,100,f);
    }

    return 0;
}
