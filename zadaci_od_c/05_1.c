// 1.Во програмот p05_02.c смести ја иницијализацијата на променливата sum во заглавието на наредбата for.

/* Program p05_02.c  
   Sumiranje so for */
#include <stdio.h>
 
/* pochnuva izvrshuvanjeto na programot */
int main()
{
   int sum; /* inicijaliziraj sum */
   int number;  /* brojot shto kje mu bide dodaden na sum */
 
   for (sum = 0, number = 2; number <= 100; number += 2 ) {
      sum += number; /* dodaj broj na sum */      
   } /* kraj for */
 
   printf( "Sumata e %d\n", sum ); /* ispechati suma */
 
   return 0; /* programot uspeshno zavrshil */
    
} /* kraj na main */

