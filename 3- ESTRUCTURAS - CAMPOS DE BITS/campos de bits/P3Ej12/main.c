#include <stdio.h>
#include <stdlib.h>
/*
union hack {
        struct {
            short int anio; //2
            char mes; //1
            char dia; //1
        } f;
        int comparo; //4
    };*/

typedef struct { //CAMPO DE BITS
    unsigned int red: 8 ; //con 8 bits
    unsigned int green : 8; //con 8 bits
    unsigned int blue : 8; //con 8 bits
} RGB24;

typedef struct { //CAMPO DE BITS
    unsigned int red: 5 ; //con 5 bits
    unsigned int green : 6; //con 5 bits
    unsigned int blue : 5; //con 6 bits
} RGB16;

RGB24 convertir16a24 (RGB16);
RGB16 convertir24a16 (RGB24);

/*??
union hack {
    RGB24 rgb24;
    RGB16 rgb16;
    int comparo;
}campoRGB;*/

int main()
{
    RGB16 pixel16 = {33,15,3};
    RGB24 pixel24 = {33,33,33};
    RGB16 pixel24Convertido;
    RGB24 pixel16Convertido;

  // pixel16Convertido = convertir16a24 (pixel16);
  // printf("Imprimo pixel convertido de 16 a 24 \n");
  // printf("red %u green %u blue %u \n", pixel16Convertido.red, pixel16Convertido.green, pixel16Convertido.blue);
   pixel24Convertido = convertir24a16(pixel24);
   printf("Imprimo pixel convertido de 24 a 16 \n");
   printf("red %u green %u blue %u \n", pixel24Convertido.red, pixel24Convertido.green, pixel24Convertido.blue);
    printf("Imprimo pixel convertido de 16 a 24 \n");
    pixel24 = convertir16a24(pixel24Convertido);
    printf("red %u green %u blue %u \n", pixel24.red, pixel24.green, pixel24.blue);

    return 0;
}
RGB24 convertir16a24 (RGB16 pixel16){

    RGB24 pixelNuevo;
    pixelNuevo.red = pixel16.red << 3;
    pixelNuevo.green = pixel16.green << 2;
    pixelNuevo.blue = pixel16.blue << 3;

    return pixelNuevo;
}

RGB16 convertir24a16 (RGB24 pixel24){

    RGB16 pixelNuevo;
    pixelNuevo.red = pixel24.red >> 3;
    pixelNuevo.green = pixel24.green >> 2;
    pixelNuevo.blue = pixel24.blue >> 3;

    return pixelNuevo;
}
