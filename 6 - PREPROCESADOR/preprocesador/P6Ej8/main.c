#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1
//Si e;l debug es 0 el preprocesador sabe que  la condicion es falsa
//entinces aparece todo lo del if en gris
//no se puede cambiar el valor de la constante en tiempo de ejcucion.

    int main(){

    int y;
    int x= 15;
     while (x<50){
       // #if DEBUG
        #ifndef DEBUG //entra siempre al if porque esta definido
            printf("x= %d \n", x);
            y= y+1;
        #endif //cierra el IF
        x++;
     }
     return 0;
    }
