#include <stdio.h>
#include <stdlib.h>
#define DIMF 50
#include <string.h>

int palindromo(char *);

int main()
{

    char palabra[DIMF];
    printf("Ingrese una cadena: \n");
    scanf("%s", palabra);
    printf("La palabra es: %s \n", palabra);

    printf ("%d" , palindromo (palabra));



    return 0;
}

int palindromo(char * palabra){
int condicion = 1;
int diml = strlen(palabra);
    for (int i=0; (palabra [i] != '\0'); i++){
        if ((palabra [i]) != (palabra [diml - 1]) ){
            condicion = 0;
            break; // si la palabra es diferente no hace falta seguir analizando
            }
    diml --;

}



return condicion;

}



