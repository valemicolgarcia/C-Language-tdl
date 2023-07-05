#include <stdio.h>
#include <stdlib.h>
#define ANOS 10
#define MESES 12
#define DIAS 30

void calcularMenores (const int [ANOS][MESES]);

int main()
{

    int info [MESES][ANOS] = {0};
    calcularMenores (info);



    return 0;
}

void calcularMenores (const int [ANOS][MESES]){
    int mes, minLluvia = 99999;
    int ano, minProm = 99999;

    for (int i=0; i<ANOS; i++){
        int suma=0;
        for (int j=0; j<MESES; j++){
            if (minLluvia > info [j][i]){
                minLluvia = info [j][i];
                mes = j;
            }
            suma += info [i][j];
        }

        if (minProm >= (suma/12)){
            minProm = suma/12;
            ano=i;
        }
        printf ("El mes que menos llovio en el año nro %d fue el %d \n" , i, mes);
    }
    printf("El año con menor precipitacion promedio es el %d", ano);


}
