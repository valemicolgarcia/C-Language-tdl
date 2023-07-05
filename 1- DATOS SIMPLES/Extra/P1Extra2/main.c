#include <stdio.h>
#include <stdlib.h>
int binarioIterativo (int);
int binarioRecursivo (int, int, int);

int main()
{   int num, binario, aux;
    printf("Lea un numero natural");
    scanf ("%d" , &num);
    //printf("El binario es %d ", binarioIterativo(num));
    aux = 1;
    binario = 0;
    printf("El binario recursivo  es %d ", binarioRecursivo(num, aux, binario));


    return 0;
}
int binarioIterativo (int num){
    int binario, dig, aux;
    aux = 1;
    binario = 0;
    while (num > 0) {
        dig = num % 2;
        binario = binario + dig * aux;
        aux *= 10;
        num /= 2;
    }
return binario;
}

int binarioRecursivo (int num,  int aux, int binario){
    int dig;
    if (num > 0) {
        dig = num % 2;
        binario = binario + dig * aux;
        binario = binarioRecursivo (num/2, aux*10, binario);

    }
return binario;
}




