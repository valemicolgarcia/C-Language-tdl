#include <stdio.h>
#include <stdlib.h>

void f (int ** p);
int main(){

    int * ptr = NULL; //calloc porq le asigno 0 con null
    f(&ptr);


    if (ptr == NULL)
        printf("ptr es NULL\n");
    else
        printf("ptr no es NULL\n");
    return 0;
}

void f (int ** ptr) {
    ptr = (int *) malloc( * sizeof(int)); //imprime null porq nunca lo lleno

    //ahora lo lleno para q me imprima no es null
    (*ptr)[0] = 1;
    (*ptr)[1] = 1;
    (*ptr)[2] = 1;
}

