#include <stdio.h>
#include <stdlib.h>

int main()
{   int edad;
    printf ("Ingrese la edad: ");
    scanf ("%d" , &edad);

    if (edad >= 40)
        printf("Tiene %d años o más \n", 40);
    else
        printf("Tiene menos de %d años  \n",40);


    //--------------------------------------------------
    int total, x;
    x = 1;
    total = 0;
    while (x <= 10) {
        total += x;
        ++x;
            }
    printf("Total = %d \n", total);

    //----------------------------------------------------

    int valor;
    printf ("Ingrese un valor: ");

    scanf("%d",&valor);
    switch (valor % 2) {
        case 0: printf("El valor es par \n");
        break;
        case 1: printf("El valor es impar \n");
        break;
        }

     //-------------------------------------------------------



     int z, y;
     printf ("Ingrese un valor: ");
     scanf("%d", &z);
     printf ("Ingrese otro valor: ");
     scanf(" %d",&y);
     printf("z + y = %d ",z+y);

     return 0;

}

