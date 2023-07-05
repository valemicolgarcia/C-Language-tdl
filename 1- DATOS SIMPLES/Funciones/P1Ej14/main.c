#include <stdio.h>
#include <stdlib.h>

int invertido (int);
int main()
{ int num;

    printf("Ingrese un numero entero\n");
    scanf ("%d", &num);
    printf ("El numero invertido es: %d" , invertido (num));

    return 0;
}
int invertido (int num) {
    int invertido, dig;
 //FUNCIÓN
    invertido =0;
     while (num != 0) {
        dig= num % 10;
        invertido *= 10;
        invertido += dig;
        num /= 10;
     }
        return invertido;
}
