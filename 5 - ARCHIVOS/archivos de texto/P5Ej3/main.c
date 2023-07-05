#include <stdio.h>
#include <stdlib.h>
#define LONG 300

int main(){
 FILE *f;

 // Abrir el archivo
 f = fopen("precipitaciones.txt", "r");
 //con la mascara r no abre el archivo correctamente -->
 //

 if (f == NULL){
 printf ("\nError al abrir archivo fuente\n");
 return 1;
 }
int i=1,num;

fscanf(f, "%d-", &num);//voy avanzando
int max = num;
int maxdia = i;

while (!feof (f)){
    if (num > max){
         max = num;
         maxdia = i;
    }

    fscanf(f, "%d-", &num);//voy avanzando
    i++;

}
printf("El dia que mas llovio es el %d \n", maxdia);
printf("El maximo de milimetros llovidos es %d \n", max);

 fclose(f);
 return 0;
}
