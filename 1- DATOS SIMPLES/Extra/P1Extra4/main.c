#include <stdio.h>
#include <stdlib.h>

int main()
{   int dig, suma, num;

    printf("Ingrese numero: ");
    scanf("%d", &num);

    while (num >= 10) {
        suma = 0;
       while (num != 0) {
        dig = num % 10;
        suma= suma + dig ;
        num /= 10;
    }
    printf("La suma es: %d \n" ,suma);
    num = suma;
    }
    return 0;
}
