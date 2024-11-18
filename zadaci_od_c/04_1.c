// 1.Модифицирај го програмот p04_01.c така да ги испуштиш break наредбите. Што се случува? Покажи пример.


/* Program: p04_01.c
   Demonstracija na case
   Dava broj na denovi vo mesec */
#include <stdio.h>
 
/* pocnuva izvrshuvanjeto */
int main()
{
   int mesec;              /* definiraj promenliva za mesec*/
 
   printf("Vnesi go mesecot so negoviot reden broj: ");
   scanf("%d", &mesec);
 
   /* vo zavisnost od vneseniot mesec najdi kolku dena ima */
   switch (mesec) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8: 
    case 10:
    case 12:
                printf("Ima 31 den\n");
                
    case 4:
    case 6:
    case 9:
    case 11:
                printf("Ima 30 dena\n");
                
    case 2:
                printf("Vo prestapni godini ima 29, a vo obichni 28 dena\n");
                
    default:
                printf("Greshen broj na mesec!\n");
   } /* kraj na switch (mesec) */
 
   return 0; /* uspeshen kraj na programot */
                            
} /* kraj na fukncijata main */

// ako gi ispustime break naredbite vo programot, 
// se slucuva poplavuvanje na slucaite vo switch izrazot, poznato kako "fall through". 
// toa znaci deka ako programata vleze vo eden slucaj (na primer, za mesec 1), taa ke prodolzi
// so izvrsuvanje na site naredbi vo slednite slucai dodeka ne se sretne break ili ne zavrsi 
// so izvrsuvanjeto na celiot switch blok.
