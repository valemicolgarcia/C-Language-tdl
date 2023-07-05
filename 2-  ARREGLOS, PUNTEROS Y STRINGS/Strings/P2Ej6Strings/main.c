#include <stdio.h>
#include <stdlib.h>
#define DIMF 26

void contarCaracter(char, char *, int *);

int main()
{
    char palabra[] = "aaazzzc"; //declaro cadena
    printf("Imprime palabra %s \n", palabra);

    char abc [DIMF] = "abcdefghijklmnopqrstuvwxyz";
    int res [DIMF]= {0};

    for (int i=0; palabra [i] != '\0'; i++){
        res[palabra[i] -'a'] ++;

    }

    printf(abc);
    printf ("\n");

    for (int i=0; i< DIMF; i++){
        printf("%d", res[i]);
    }

    return 0;
}

