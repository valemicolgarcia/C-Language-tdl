#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    float pi = 3;
    int n = 2;
    for (int i = 0; i<6; i++) {
        pi = pi + (( (pow (-1, i) ) * 4) / (n * (n+1) * (n+2)));
        n += 2;
    }
    printf ("El numero pi es: %f " , pi);
    return 0;
}
