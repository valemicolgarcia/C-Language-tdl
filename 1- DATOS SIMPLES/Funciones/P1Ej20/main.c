#include <stdio.h>
#include <stdlib.h>
int damePar ();
int main()
{ int n;
int i;
    printf("Ingrese cantidad de veces n = ");
    scanf( "%d", &n);
    for (i = 0; i < n; i++) {
        printf("El numero par es: %d \n" , damePar());
    }
    return 0;
}
int damePar () {
static int a = -2;
a +=2;
return a;
}
