// 1.Кога ги дефинираме функциите copy1 и copy2 во p09_13.c, 
// првиот аргумент мора да е доволно голем за да ги добие 
// вредностите на вториот аргумент. Што тоа значи?

//odgovor

//Koga gi definira funkcijite copy1 i copy2, 
// prviot argument (s1) mora da e dovolno goljem za da go prima stringot od
//vtoriot argument (s2). Toa znaci deka niza s1 treba da ima dovoljno prostor
//za svite karakteri od s2, vklučujući i simbolot za kraj na string (\0).
//Ako s1 e premala, ke dojde do prepisuvanje na memorija i problemi vo programot.


/* Program p09_13.c
   Kopiranje na string koristejki notacija na niza i
   pokazhuvachka notacija. */
#include <stdio.h>
 
void copy1( char *s1, const char *s2 ); /* prototip */
void copy2( char *s1, const char *s2 ); /* prototip */
 
int main()
{
   char string1[ 10 ];          /* kreiraj niza string1 */
   char *string2 = "Zdravo";     /* kreiraj pokazhuvach kon string */
   char string3[ 10 ];          /* kreiraj niza string3 */
   char string4[] = "Dobar den"; /* kreiraj pokazhuvach kon string */
 
   copy1( string1, string2 );
   printf( "string1 = %s\n", string1 );
 
   copy2( string3, string4 );
   printf( "string3 = %s\n", string3 );
 
   return 0; /* uspeshen kraj */
 
} /* kraj main */
 
/* kopiraj go s2 vo s1 koristejki notacija na niza */
void copy1( char *s1, const char *s2 )
{
   int i; /* brojach */
   /* pomini niz stringovite */
   for ( i = 0; ( s1[ i ] = s2[ i ] ) != '\0'; i++ ) {
      ;   /* vo teloto nishto ne se pravi */
   } /* kraj for */
} /* kraj na funkcijata copy1 */
 
/* kopiraj go s2 vo s1 koristejki pokazhuvachka notacija */
void copy2( char *s1, const char *s2 )
{
   /* pomini niz stringovite */
   for ( ; ( *s1 = *s2 ) != '\0'; s1++, s2++ ) {
      ;   /* nishto ne se pravi vo teloto na for */
   } /* kraj for */
} /* kraj na funkcijata copy2 */
