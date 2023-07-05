#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIMF 8 //campos


typedef struct { //representa una posicion en el espacio
    float minimo;
    float maximo;
    float promedio;
} info;



int main()
{

    info infoV [DIMF]; //contiene info de los campos del archivo

    int i;
    float a;

     // Abrir el archivo
     FILE *f;
     f = fopen("vinos.txt", "r");
     // errores
     if (f == NULL){
     printf ("\nError al abrir archivo fuente\n");
     return 1;
     }
    char tipo [10];
    //LEO LA PRIMER LINEA --> nombres de los campos
    char campos [100];

    //char atributo[50]; //no entendi esta de dolo
   /* for (i = 0; i < DIMF; i ++){
        fscanf(f, "%[^;];", campos); //mascara para escribir dos
       // strcpy(infoV[i], campos);

    }*/

    fgets (campos, 100, f);
    //INICIALIZO EL VECTOR
    int j;
    for (j=0;j<DIMF;j++){
        infoV[j].promedio=0;
        infoV[j].minimo=99999;
        infoV[j].maximo=-1;
    }

    //LECTURA Y CALCULO
    int cantLineas = 0;

    //PRIMER LINEA
    cantLineas++;
    printf("LINEA NUMERO: %d \n", cantLineas);
        for (i=0;i<DIMF;i++) { //LEO CAMPOS CON FLOAT
            fscanf(f, "%f;", &a);
            printf("Imprimo el numero leido %f \n", a);
            infoV[i].promedio += a;
          //  printf("La suma parcial es: %f \n",infoV[i].promedio);
            if ( a > infoV[i].maximo)
                infoV[i].maximo=a;
            if (a < infoV[i].minimo)
                infoV[i].minimo=a;
        }
        fscanf (f,"%s", tipo); //avanzo en el archivo (PREGUNTAR COMO HACER ESTO SIN GUARDARLO)


    while (!feof (f)){
        cantLineas++;
        printf("LINEA NRO: %d \n", cantLineas);
        for (i=0;i<DIMF;i++) { //LEO CAMPOS CON FLOAT
            fscanf(f, "%f;", &a);
            printf("Imprimo el numero leido %f \n", a);
            infoV[i].promedio += a;
          //  printf("La suma parcial es: %f \n",infoV[i].promedio);
            if ( a > infoV[i].maximo)
                infoV[i].maximo=a;
            if (a < infoV[i].minimo)
                infoV[i].minimo=a;
        }
        fscanf (f,"%s\n", tipo); //avanzo en el archivo (PREGUNTAR COMO HACER ESTO SIN GUARDARLO) POR QUE \n.?????????
    }


    infoV[i].promedio/=cantLineas;
    printf("\n");
    //IMPRIMO LA INFO


    FILE *arch;
    arch = fopen("reporte_vinos.txt", "w");

    fprintf(arch, "ATRIBUTOS  :");
  //  fprintf(arch, "%s\n", campos);
    fprintf(arch, "Acidez Fija\tAcidez Volatil\tAcido Citrico\tAzucares Residuales\tPH\tSulfatos\tAlcohol\tCalidad     \n");

    fprintf(arch, "\n");
    fprintf(arch, "PROMEDIO   :");
    printf("PROMEDIO \n");
    for (i=0;i<DIMF;i++){
        printf("%.2f / ", infoV[i].promedio);
        fprintf(arch, "%.2f\t\t", infoV[i].promedio);
    }
    printf("\n");
    printf("MAXIMO \n");
    fprintf(arch, "\n");
    fprintf(arch, "  MAXIMO   :");
    for (i=0;i<DIMF;i++){
        printf("%.2f / ", infoV[i].maximo);
        fprintf(arch, "%.2f\t\t", infoV[i].maximo);
    }
        printf("\n");
    fprintf(arch, "\n");
    printf("MINIMO \n");
    fprintf(arch, "  MAXIMO   :");
    for (i=0;i<DIMF;i++){
        printf("%.2f / ", infoV[i].minimo);
        fprintf(arch,"%.2f\t\t", infoV[i].minimo);
    }
        printf("\n");






    return 0;
}
