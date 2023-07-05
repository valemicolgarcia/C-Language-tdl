#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIN "ZZZ"

int main()
{

    char fin [4] = "ZZZ"; //FIN de la lectura
    char palabra [20] = {0};


    printf("Ingrese una palabra");
    int cant = 0;
    scanf("%s", palabra);
    printf("------------------------------");
    while (strcmp (palabra, fin)){
            if (strlen (palabra) == 5)
                cant ++;
        printf("Ingrese otra palabra");
        scanf("%s", palabra);
    }
    printf("La cantidad de palabras con 5 caracteres es de: %d", cant);

    return 0;
}
