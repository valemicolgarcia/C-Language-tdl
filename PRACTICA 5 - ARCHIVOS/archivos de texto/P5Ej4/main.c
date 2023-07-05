#include <stdio.h>
#include <stdlib.h>
#define LONG 300

int main(){
 FILE *f;

 // Abrir el archivo
 f = fopen("apuestas.txt", "r");
 //

 if (f == NULL){
 printf ("\nError al abrir archivo fuente\n");
 return 1;
 }

int a; //codigo
float b; //monto
float total = 0;

fscanf(f, "%d|%f;", &a, &b);

while (!feof (f)){
    total+= b;
    fscanf(f, "%d|%f;", &a, &b);
}

printf("El monto total %f", total);

 fclose(f);
 return 0;
}
