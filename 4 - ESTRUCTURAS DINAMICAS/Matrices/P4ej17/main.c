#include <stdio.h>
#include <stdlib.h>
#define N 10

int*** crearTensor(int t){
 int i,j;
 int*** a;
     a = (int***) calloc(t,sizeof(int**));
     for (i=0; i<t; i++){
        a[i] = (int**) calloc(t, sizeof(int*));
     for (j=0; j<t; j++){
        a[i][j] = (int*) calloc(t, sizeof(int));
     }
     }

 return a;
}

int main()
{
 int*** e;
 //un tensor es un arreglo de tres dimensiones
 //por eso es que la variable e tiene que ser de ***
 e = crearTensor(N);

 return 0;
}
