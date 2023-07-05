#include <stdio.h>
#include <stdlib.h>

int main()
{


   int a = 1;
   int b = 2;
   int c = 4;
   int * p1, *p2;
   p1 = &a; //
   p2 = &c;
   p1 = (*p2)++;
   printf ("%d", (*p2)++);
    p2 = &b;
    p1 += *p2;
    p1 = p2;
    ++*p1;
    p1 = &a;
    *p2*=*p1;
    c = *p2+*p1;
   a = *p1 = ++*p2;


    return 0;
}
