/*
5.Desarrolle un programa que utilice un tipo de datos que modele las figuras geométricas
bidimensionales: circulo, elipse, triángulo, cuadrado y rectángulo con sus propiedades (radio, lado/s,
base, etc.). Implemente una única función que permita calcular la superficie de cualquier figura.
El programa debe leer por teclado los datos de una figura e imprimir su superficie.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef enum {CIRCULO=1, ECLIPSE, TRIANGULO, CUADRADO,RECTANGULO} fig;

typedef struct { //rectangulo y triangulo --> same estructura
                int base;
                int altura;
            }rtt;
typedef struct { //eclipse
                int radio_a;
                int radio_b;
            }ecc;

typedef struct  {
        int tipo; //identificador de la figura que trabajo. (me sirve el enum)
        union {
            int lado; //cuadrado o circulo
            rtt rt; //rectangulo o triangulo
            ecc ec; //eclipse
        }datos;
} figGeometrica;

//------------------------------PROTOTIPOS DE FUNCIONES----------------------------------------
void leerFigura (figGeometrica * f);
void imprimirFigura(figGeometrica f, const char * recuperarNombre []);
float calcularArea (figGeometrica f);

//-------------------------------MAIN------------------------------------
int main()
{
    const char * recuperarNombre[] = {"Circulo", "Eclipse", "Triangulo", "Cuadrado", "Rectangulo" };

    figGeometrica f; //declaro figura
    leerFigura (&f);
    imprimirFigura(f, recuperarNombre);
    float area = calcularArea(f);
    printf("El area de la figura %s es: %f", recuperarNombre[f.tipo], area);


    //--------------------------------------------
    return 0;
}

void leerFigura (figGeometrica * f){

    printf("\n");
    printf("Ingrese figura a trabajar: \n");
    printf("REFERENCIAS: 1=Circulo, 2=Eclipse, 3=Triangulo, 4=Cuadrado, 5=Rectangulo \n");
    scanf("%d", &(f->tipo));
    switch (f->tipo){
    case CIRCULO:
            printf("Ingrese radio \n");
            scanf("%d", &(f->datos.lado));
            break;
    case ECLIPSE:
            printf("Ingrese radio mayor \n");
            scanf("%d", &(f->datos.ec.radio_a));
            printf("Ingrese radio mayor \n");
            scanf("%d", &(f->datos.ec.radio_b));
            break;
    case TRIANGULO:
            printf("Ingrese base \n");
            scanf("%d", &(f->datos.rt.base));
            printf("Ingrese altura \n");
            scanf("%d", &(f->datos.rt.altura));
            break;
    case CUADRADO:
            printf("Ingrese lado \n");
            scanf("%d", &(f->datos.lado));
            break;
    case RECTANGULO:
        printf("Ingrese lado1 \n");
            scanf("%d", &(f->datos.rt.base));
            printf("Ingrese lado2 \n");
            scanf("%d", &(f->datos.rt.altura));
            break;
    default:
        printf("OPCION NO VALIDA! \n");
        break;
    }
    printf("\n");
}

void imprimirFigura(figGeometrica f, const char * recuperarNombre []){
    printf("La figura a trabajar es: %s", recuperarNombre[f.tipo] );

}

float calcularArea (figGeometrica f){
        float area;
        switch (f.tipo){
            case CIRCULO:
                    area = (float)(3.14 * pow (f.datos.lado, 2));
                    break;
            case ECLIPSE:
                    area= (float) (3.14 * f.datos.ec.radio_a * f.datos.ec.radio_b);
                    break;
            case TRIANGULO:
                    area = (float)((f.datos.rt.base * f.datos.rt.altura) / 2);
                    break;
            case CUADRADO:
                    area = (float) (pow(f.datos.lado, 2));
                    break;
            case RECTANGULO:
                    area = (float) (f.datos.rt.base * f.datos.rt.altura);
                    break;
            }
            printf("\n");


return area;
}

