// 4. Во примерот p03_01.c, во наредбата printf наместо спецификаторот за конверзија  %f,
//  поставете го спецификаторот %d. Што се случува и зошто?

/* Program 3.1: p03_01.c
    Manipulacija so decimalni broevi */
#include <stdio.h>
float result; /* Rezultat od delenje */
int main()
{
result = 7.0 / 22.0;
printf("Rezultatot e %d\n", result);
return (0);
}


// Ako vo primerot p03_01.c koristite %d namesto %f vo naredbata printf,
//  ke se sluci nepredvidljivo ponasanje. Specifikatorot %d e za celobrojni 
//  vrednosti (tip int), a %f e za decimalnite broevi (tip float).

// Ako imate promenlivata deklarirana kako float i obidete da ja odpecatime so %d,
//  ke se proba da se odpecati vrednosta na promenlivata kako cel broj, a to ne e pravilno.

// Decimalnite broevi se cuvaat na specificen nacin vo memorijata, a celobrojnite broevi na drug nacin.

