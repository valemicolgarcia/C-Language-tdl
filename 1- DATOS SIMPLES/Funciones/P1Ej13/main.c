#include <stdio.h>
#include <stdlib.h>
int primo (int);
int main()
//prototipo de la funcion

{   int num;
    int booleano;

    printf("Ingrese un numero ");
    scanf("%d", &num);

    booleano = primo (num);

    if (booleano)
      printf("No es primo");
    else
      printf("Es primo");

    return 0;

    }

int primo (int num)
{   int i;
    int booleano;
    booleano = 0;
    for (i = 2; i <= num - 1; i++) {
      if ((num % i) == 0) {
        booleano = 1;
        break; }
    }
    return booleano;



}
