/*Escriba un programa que lea desde teclado números enteros de una cifra (del 0 al 9) y que cree dos
archivos, los cuales almacenen los números leídos. El primer archivo debe llamarse “numeros.txt” y
contener en formato texto todos los números leídos en forma consecutiva. El segundo archivo debe
llamarse “numeros.dat” y contener todos los números leídos en formato binario.
▪ Una vez ejecutado el programa, utilice un editor de texto (como por ejemplo: el Bloc de notas
en MS Windows, o Gedit en GNU/Linux) para abrir el archivo de texto y corroborar que la
información almacenada sea la correcta. Usando el mismo editor, intente abrir el archivo
binario. ¿Es posible visualizar los números? ¿Por qué cree que no es posible?
▪ Compare los tamaños que ocupan cada archivo. ¿Cuál es más grande? ¿En qué ocasiones
cree usted que sería mejor utilizar cada tipo de archivos?
*/

//EJERCICIO 8

#include <stdio.h>
#include <stdlib.h>

int main()
{


     FILE *f, *fb;

    //ABRO EL ARCHIVO
    f = fopen("numeros.txt", "w"); //archivo de texto
    fb = fopen("numeros2.txt", "wb"); //archivo binario

    //VERIFICO ERRORES
    if (f == NULL) {
        printf("\nError al abrir el archivo de texto\n");
        return 1;
    }
    if (fb == NULL) {
        printf("\nError al abrir el archivo binario\n");
        return 1;
    }

    int num;
    printf("Ingrese un numero \n");
    scanf ("%d", &num);

    while (num != 0){
        fprintf(f, "%d", num); //ARCHIVO DE TEXTO
        fwrite(&num, sizeof (int), 1, fb); //ARCHIVO BINARIO
        printf("Ingrese un numero \n");
        scanf ("%d", &num);
    }

    //CIERRE DE ARCHIVOS
    fclose (f);
    fclose (fb);


    return 0;
}
