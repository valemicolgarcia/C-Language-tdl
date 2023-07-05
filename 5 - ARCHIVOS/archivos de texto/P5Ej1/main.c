#include <stdio.h>
#include <stdlib.h>
#define LONG 300
int main(){
 FILE *f;
 char linea[LONG];
 // Abrir el archivo
 f = fopen("archivo.txt", "r");
 //con la mascara r no abre el archivo correctamente -->
 //

 if (f == NULL){
 printf ("\nError al abrir archivo fuente\n");
 return 1;
 }

 fgets(linea,LONG,f);

 while (!feof(f)){
// imprimir la linea en la pantalla
 puts(linea);
 // leer una linea del archivo
 fgets(linea,LONG,f);


 }
 fclose(f);
 return 0;
}
