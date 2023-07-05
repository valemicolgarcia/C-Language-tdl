#include <stdio.h>
#include <stdlib.h>

struct separado{
    int x;
    int y;
    int ancho;
    int alto;
};

struct punto{
    int x;
    int y;
}; //declaro dos variables de tipo punto

//acceso junto: hago un vector que tenga x,y,ancho,alto -->accedo a todos al mismo tiempo

union acceso {
    struct separado sep;
    struct punto puntos [2];
    int vector [4];
    //int vector [] = {x,y,ancho,alto};

};

int main()
{
    union acceso access;
    //acceso separado - le asigno valores
    access.sep.alto = 1;
    access.sep.ancho = 2;
    access.sep.x= 3;
    access.sep.y = 4;
    printf("\n");
    printf("ACCESO SEPARADO: El valor del alto es %d \n" , access.sep.alto);
    printf("ACCESO SEPARADO: El valor del ancho es %d \n" , access.sep.ancho);
    printf("ACCESO SEPARADO: El valor de x es %d \n" , access.sep.x);
    printf("ACCESO SEPARADO: El valor de y es %d \n" , access.sep.y);
    printf("\n");
    access.puntos[].x = 1;
    access.punto1.y = 2;
    printf("ACCESO POR PUNTO 1: El valor de x es %d \n" , access.punto1.x);
    printf("ACCESO POR PUNTO 1: El valor de y es %d \n" , access.punto1.y);
    printf("\n");//------------------------------------
    access.punto2.x = 3;
    access.punto2.y = 4;
    printf("ACCESO POR PUNTO 2: El valor de x es %d \n" , access.punto2.x);
    printf("ACCESO POR PUNTO 2: El valor de y es %d \n" , access.punto2.y);
    printf("\n");//----------------------------------------
    int x = 1;
    int y = 2;
    int ancho = 3;
    int alto = 4;
    access.vector[0] = x;
    access.vector[1] = y;
    access.vector[2] = ancho;
    access.vector[3] = alto;
    printf("IMPRIMO VECTOR: [0] = x,[1] = y, [2] = ancho, [3] = alto \n");
    for (int i = 0; i<4; i++){
    printf("%d \n", access.vector[i]);
    }
    printf("\n");
    //lo ultimo que jice fue usar el vector de la union, por lo tanto se supone que el resto de los accesos quedaron con basura
    //DEMUESTRO ESO:
    printf("Los valores del acceso por separado CAMBIAN - ya que uso estructura de tipo union. \n");
    printf("ACCESO SEPARADO: El valor del alto es %d \n" , access.sep.alto);
    printf("ACCESO SEPARADO: El valor del ancho es %d \n" , access.sep.ancho);
    printf("ACCESO SEPARADO: El valor de x es %d \n" , access.sep.x);
    printf("ACCESO SEPARADO: El valor de y es %d \n" , access.sep.y);
    printf("\n");


    return 0;
}
