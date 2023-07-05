#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char calcularPuntaje (int);
int main()
{   int i, op2, op1, result, total;
    srand(time(NULL));
    total = 0;
    for (i=0; i<4; i++){
        op1= rand()%101;
        op2 = rand()%101;
        printf("%d + %d = \n", op1, op2);
        printf("Ingrese resultado ");
        scanf("%d", &result);
        if (result == (op1 + op2)){
            printf("Respuesta correcta! \n");
            total++;
        }
        else
            printf("Respuesta incorrecta \n");
    }
    printf(" \n");
    printf ("La nota obtenida es = %c" , calcularPuntaje(total));
    return 0;
}
char calcularPuntaje (int total){
    char nota;
    switch (total) {
        case (0): nota = 'E';
        break;
        case (1): nota = 'D';
        break;
        case (2): nota = 'C';
        break;
        case (3): nota = 'B';
        break;
        case (4): nota = 'A';
        break;
    }
    return(nota);
}
