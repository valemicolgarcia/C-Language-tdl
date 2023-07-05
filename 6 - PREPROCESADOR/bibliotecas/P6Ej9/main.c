
    /*Implemente la biblioteca imath.h, la cual contiene funciones matemáticas para enteros. La misma debe


    contener las siguientes funciones:

    a. int potencia(int x, int y) – Eleva x a la y-ésima potencia.
    b. int cuadrado(int x) – Eleva x al cuadrado.
    c. int cubo(int x) – Eleva x al cubo.
    d. int absoluto(int i) – Retorna el valor absoluto entero de i.
    e. int factorial (int i) – Retorna el factorial de i.
    f. int sumatoria (int i) – Retorna la sumatoria de 0 hasta i.
    g. int multiplo (int x, int y) – Retorna 1 si y es divisor de x, 0 en otro
    caso.
    h. int divisor (int x, int y) – Retorna 1 si y es múltiplo de x, 0 en otro
    caso.
    i. int par (int i) – Retorna 1 si i es par, 0 en otro caso.
    j. int impar (int i) – Retorna 1 si i es impar, 0 en otro caso.

    Una vez implementadas todas las funciones de biblioteca, escriba un programa que lea números enteros e
    imprima el cuadrado y el cubo de aquellos números que son pares y el factorial de aquellos que son
    impares. La lectura finaliza con el ingreso del 0.
    */

#include <stdio.h>
#include <stdlib.h>
#include "imath.h"

int main()
{
    //------------------------------------------------------------
    int base;
    int exponente;
    printf ("POTENCIA: \n");
    printf ("Ingrese base y exponente: \n");
    scanf ("%d", &base);
    scanf ("%d", &exponente);
    printf ("La potencia es %d \n", potencia (base, exponente));
    //--------------------------------------------------------------------
    printf ("CUADRADO: \n");
    printf ("Ingrese numero para elevar al cuadrado \n");
    int num;
    scanf ("%d", &num);
    printf ("El cuadrado del numero es  %d \n", cuadrado (num));
    //--------------------------------------------------------------------
    printf ("CUBO: \n");
    printf ("Ingrese numero para elevar al cubo \n");
    scanf ("%d", &num);
    printf ("El cuadrado del numero es  %d \n", cubo (num));
    //------------------------------------------------------------------
    printf ("VALOR ABSOLUTO: \n");
    printf ("Ingrese numero para calcular el valor absoluto \n");
    scanf ("%d", &num);
    printf ("El cuadrado del numero es  %d \n", absoluto (num));
    //------------------------------------------------------------------
    printf ("FACTORIAL: \n");
    printf ("Ingrese numero para calcular el valor absoluto \n");
    scanf ("%d", &num);
    printf ("El cuadrado del numero es  %d \n", factorial (num));
    //------------------------------------------------------------------
    printf ("SUMATORIA: \n");
    printf ("Ingrese numero para calcular la sumatoria \n");
    scanf ("%d", &num);
    printf ("La sumatoria %d \n", sumatoria (num));
    //------------------------------------------------------------------
    printf ("MULTIPLO: \n");
    printf ("Ingrese numero \n");
    scanf ("%d", &num);
    int div;
    printf ("Ingrese divisor \n");
    scanf ("%d", &div);
    printf ("El numero es multiplo? %d \n", multiplo (num, div));
    //------------------------------------------------------------------
    printf ("DIVISOR: \n");
    printf ("Ingrese numero \n");
    scanf ("%d", &num);
    printf ("Ingrese divisor \n");
    scanf ("%d", &div);
    printf ("El numero es divisor? %d \n", divisor (num, div));
    //------------------------------------------------------------------
    printf ("PAR: \n");
    printf ("Ingrese numero para saber si es par \n");
    scanf ("%d", &num);
    printf ("El numero es par? %d \n", par (num));
    //------------------------------------------------------------------
    printf ("IMPAR: \n");
    printf ("Ingrese numero para saber si es impar \n");
    scanf ("%d", &num);
    printf ("El numero es impar? %d\n", impar (num));
    //-------------------------------------------------------------------

    return 0;
}
