#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define forn(i, n) for(i = 0; i < n; i++)
#define DIMF 5

//CODIGO HECHO CON JOACO-------------------------------------------------------------------------
typedef struct { // size 8 bits = 1 byte
    unsigned int num: 4; // 2 a la 4 es 16 --> necesitaba 12 nums ;  4 (decimal) ===> 0100 (binario)
    unsigned int palo: 2; //2 bits para representar 4 colores: 2 a la 2 es 4
    unsigned int color: 1; // con 1 bit bastaba
    unsigned int relleno: 1; //para completar los 8 bits
} carta;

//-----------------------PROTOTIPOS DE FUNCIONES----------------------------------
void mezclarMazo(carta mazo [], int diml);
void imprimirCarta (carta c, const char recuperarNumero[], const char * recuperarPalo[],const char * recuperarColor[]);
void imprimirMazo (carta mazo[], const int diml, const char recuperarNumero[], const char * recuperarPalo[], const char * recuperarColor[]);
void llenarMazo (carta mazo[], const int diml);
carta devolverCarta (carta mazo[], int i, int * diml);

//-----------------------------------------MAIN-----------------------------------------------------
int main()
{
    srand(time(NULL)); //voy a usar el random
    carta mazo[DIMF]; //vector de 48 cartas : carta es un campo de bits
    int diml = DIMF; //dimension logica que voy a modificar luego

    //Tenemos 12 cartas, del 1 al 12, estos son vectores que contienen los nombres que quwremos imprimir en determinadas posiciones
    const char recuperarNumero[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9','J', 'Q', 'K'}; // char * = cadena de caracteres (string)
    const char * recuperarPalo[] = {"Corazon", "Diamante", "Trebol", "Pica" };
    const char * recuperarColor[] = {"Rojo", "Negro" };

    printf("Dimension logica del mazo al principio: %d", diml);
    printf("\n");

    printf("MAZO ORDENADO: \n");
    llenarMazo(mazo, diml); // paso el vector de cartas y la dimension
    imprimirMazo(mazo, diml, recuperarNumero, recuperarPalo, recuperarColor);
    printf("\n");

    printf("MAZO MEZCLADO: \n");
    mezclarMazo(mazo, diml);
    imprimirMazo(mazo, diml, recuperarNumero, recuperarPalo, recuperarColor);
    printf("\n");

    printf("SACO UNA CARTA \n");
    int i = rand() % diml; //numero de carta a devolver
    printf("La posicion de la carta es %d \n",i);
    carta x = devolverCarta (mazo, i, &diml); //mandamos & de diml porque hay que modificarla
    imprimirCarta(x,recuperarNumero, recuperarPalo, recuperarColor);

    printf("\n");
    printf("Dimension logica del mazo al final: %d", diml);
    printf("\n");
    printf("MAZO RESULTANTE: \n");
    imprimirMazo(mazo, diml, recuperarNumero, recuperarPalo, recuperarColor);
    printf("\n");


    return 0;
}
//-------------------------------FUNCIONES-------------------------------------------------------------

//llenar mazo!!-------------------
void llenarMazo (carta mazo[], const int diml) {
    int k;
    for (k = 0; k < diml; k++) {
        mazo[k].num = (k % 12) + 1; //1%12 = 0+1= 1; 12%12 = 0 +1 = 1;
        mazo[k].palo = (k % 4); //0%4> 0; 1%4=0
        mazo[k].color = (k % 2);
    }
}

//imprimir carta!!------------
void imprimirCarta (carta c,  const char recuperarNumero[],  const char * recuperarPalo[], const char * recuperarColor[]) {
  // printf("CARTA --> num: %u       palo: %u        color: %u \n", c.num, c.palo, c.color);
   //int n = (int)c.num - 1;
   //int p = (int)c.palo;
   //int o = (int) c.color;
   printf("CARTA --> num: %c       palo: %s        color: %s \n", recuperarNumero[c.num - 1], recuperarPalo[c.palo], recuperarColor[c.color]);
}

//imprimir mazo!!--------------
void imprimirMazo (carta mazo[], const int diml, const char recuperarNumero[], const char * recuperarPalo[], const char * recuperarColor[]) {

    for (int i=0; i<diml; i++){
        imprimirCarta(mazo[i], recuperarNumero, recuperarPalo, recuperarColor);
    }

}

//mezclar!!----------------------
void mezclarMazo(carta mazo [], int diml){
int numX;
carta aux;
for (int i=0; i<diml; i++){
    numX= rand()%diml; //numero random dentro del mazo para buscar carta
    aux= mazo[i]; //me guardo la carta actual
    mazo [i] = mazo [numX]; //intercambio la carta actual con la de una posicion x
    mazo[numX]= aux; //intercamio con el auxiliar que me guarde
}
}

carta devolverCarta (carta mazo[], int pos, int * diml){

    carta c = mazo[pos]; //saco la carta del mazo
    for (int i = pos; i<(*diml); i++){
        mazo[i]=mazo[i+1]; //piso el valor y le asigno el que le sigue
    }
    (*diml) --;

    return c;
}
//fin.......

