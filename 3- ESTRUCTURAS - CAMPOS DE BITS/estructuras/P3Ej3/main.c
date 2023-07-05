#include <stdio.h>
#include <stdlib.h>
#define DIM 2


struct direccion {
    char calle [50]; //arreglo de 50 caracteres
    char ciudad [30]; //arreglo de 30 caracteres
    int codigo_postal;
    char pais [40]; //arreglo de 40 caracteres
};

struct alu {
    char apellido [50]; //arreglo de 50 caracteres
    char nombre [50]; //arreglo de 50 caracteres
    char legajo [8]; //arreglo de 8 caracteres
    float promedio;
    struct direccion domicilio; //domicilio de tipo direccion (estructura)
};

typedef struct alu alumno; //struct alu lo redefino a --> alumno (TIPO DE DATO)



//PROTOTIPOS DE FUNCIONES------------------------------------------------------------------------------------
void imprimirAlumno (alumno); //parametro por valor
void inicializarAlumno (alumno *); //parametro por referencia
void mejorPromedio (alumno [], int); //parametro por valor
void inicializarVector (alumno [] ,int); //parametro por referencia

int main()
{
    printf("EJERCICIO 3 - PRACTICA 4\n");
    alumno a; //declaro variable de tipo alumno
    inicializarAlumno(&a); //le mando la direccion para que me cambie los valores
    imprimirAlumno(a); //imprimo el alumno
    printf("\n");
    //arreglo de 30 elementos alumno
    alumno v [DIM];
    inicializarVector (v,DIM);
    mejorPromedio (v,DIM);



    return 0;
}


void imprimirAlumno (alumno a){
    printf("\n");
    printf("IMPRIME ALUMNO: \n");
    printf("\n");
    printf("El apellido del alumno es: %s \n" , a.apellido);
    printf("El nombre del alumno es: %s \n" , a.nombre);
    printf("El legajo del alumno es: %s \n" , a.legajo);
    printf("El promedio del alumno es: %f \n" , a.promedio);

    printf("La direccion del alumno es: \n");
    printf("Calle: %s \n" , a.domicilio.calle);
    printf("Ciudad: %s \n" , a.domicilio.ciudad);
    printf("Código Postal: %d \n" , a.domicilio.codigo_postal);
    printf("País %s \n" , a.domicilio.pais);

}

void inicializarAlumno (alumno * a) {
    printf("\n");
    printf("INICIALIZO ALUMNO \n");
    //inicializar valores por teclado
    printf("Ingrese apellido - 50 caracteres \n");
    scanf("%s", a -> apellido);
    printf("Ingrese nombre - 50 caracteres \n");
    scanf("%s", a -> nombre);
    printf("Ingrese legajo - 8 caracteres \n");
    scanf("%s", a -> legajo);
    printf("Ingrese promedio - float \n");
    scanf("%f", &(a -> promedio)); //le tengo q mandar & porque es numero
    //se puede modularizar
    printf("Leo domicilio - estructura a inicializar: \n");

    printf("Ingrese calle - 50 caracteres \n");
    scanf("%s", a -> domicilio.calle);
    printf("Ingrese ciudad - 30 caracteres \n");
    scanf("%s", a -> domicilio.ciudad);
    printf("Ingrese codigo postal - int \n");
    scanf("%d", &(a -> domicilio.codigo_postal)); //le tengo q mandar & porque es numero
    printf("Ingrese pais - 40 caracteres \n");
    scanf("%s", a->domicilio.pais);

    //no puedo leer ciudades de dos palabras pq se me traba para leer el int despues
}

void inicializarVector (alumno v[] ,int cant){
    printf("INICIALIZO EL VECTOR: \n");
     for (int i=0; i< DIM; i++){
        inicializarAlumno(&(v[i]));
    }
}


void mejorPromedio (alumno v[], int cant){
    float max = -1;
    int pos;

    for (int i=0;i<cant;i++){
        if (v[i].promedio > max){
            max = v[i].promedio; //int a int
            pos = i; //me guardo la posicion
        }
    }
    //imprimo resultados
    printf("El maximo promedio es: %f \n" , max);
    printf("El nombre es: %s \n", v[pos].nombre);
    printf("El apellido es: %s \n", v[pos].apellido);


}
