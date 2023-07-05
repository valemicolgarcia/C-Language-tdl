#include <stdio.h>
#include <stdlib.h>
#define LONG 300

/*) Escriba un programa que procese un archivo de texto e informe la cantidad de caracteres
minúsculas, mayúsculas y dígitos que posee
*/


int main(){

 FILE *arch;


 // Abrir el archivo
 arch = fopen("archivo2.txt", "r");
 //con la mascara r no abre el archivo correctamente -->
 //

 if (arch == NULL){
 printf ("\nError al abrir archivo fuente\n");
 return 1;
 }

int mayusculas = 0;
int minusculas = 0;
int digitos = 0;

char c; //declaro variable tipo char
 c= fgetc(arch); //leo un caracter de un archivo


 while (!feof(arch)){
        if ((c >= 'a')&& (c <= 'z'))
    minusculas++;
else {
    if ((c >= 'A') && (c <= 'Z'))
        mayusculas++;
    else
        if ((c>= '1') && (c<= '9'))
            digitos++;
}


 c= fgetc(arch); //leo un caracter de un archivo

 }

 printf("La cantidad de mayusculas es de: %d \n", mayusculas);
 printf("La cantidad de minusculas es de: %d \n", minusculas);
 printf("La cantidad de digitos es de: %d \n", digitos);

 fclose(arch);
 return 0;
}
