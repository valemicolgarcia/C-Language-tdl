#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor1, valor2;
    char operador;

    printf ("Ingrese un valor: ");
    scanf("%d",&valor1);

    printf ("Ingrese otro valor: ");
    scanf(" %d", &valor2);

    printf ("Ingrese operador");
    scanf(" %c",&operador);

    switch (operador) {
        case ('+'):
            printf ("La suma de los valores es = %d ", (valor1 + valor2));
        break;
        case ('-'):
            printf("La resta de los valores es = %d \n",(valor1 - valor2));
        break;
        case ('*'):
            printf("La división de los valores es = %d \n" , (valor1 / valor2));
        break;
        case ('/'):
            printf("La multiplicación de los valores es = %d \n" , (valor1 * valor2));
        break;
        default: printf("Ingresa un comando correcto");
        }

    return 0;
}
