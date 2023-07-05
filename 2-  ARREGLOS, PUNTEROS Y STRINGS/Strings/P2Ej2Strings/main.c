#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char fin [4] = "XXX"; //FIN de la lectura
    char palabra [20] = {0};
    int pos;
    printf("Ingrese una palabra");
    int cant = 0;
    scanf("%s", palabra);
    while (strcmp (palabra, fin)){
        pos = strlen (palabra) - 1;
        if(palabra [pos] == 'o')
            cant++;
        printf("Ingrese otra palabra");
        scanf("%s", palabra);
    }
    printf("La cantidad de palabras que terminan con la letra o es de: %d", cant);

    //-------------------------------------------------------
    return 0;
}
