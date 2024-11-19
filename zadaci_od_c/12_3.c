// 3. Да се открие и опише што работи следниот програм?
/* Program vezba11_01.c
   Shto raboti sledniot program?*/
#include <stdio.h>
 
int misterija( unsigned bitovi ); 
 
int main()
{ 
   unsigned x; 
   printf( "Vnesi cel broj: " );
   scanf( "%u", &x );
   printf( "Rezultatot e %d\n", misterija( x ) );
   return 0; 
} 
 
int misterija( unsigned bitovi )
{ 
   unsigned i;              
   unsigned maska = 1 << 31; 
   unsigned total = 0;      
 
   for ( i = 1; i <= 32; i++, bitovi <<= 1 ) {
      if ( ( bitovi & maska ) == maska ) { 
         total++;
      } 
   } 
   return !( total % 2 ) ? 1 : 0;
} 


// Ovaj program broi brojot na 1-ki vo binarnata predstava na daden unsigned celobrojni broj i 
// vrakja 1 ako brojot na 1-ki e paren, ili 0 ako e neparen.

// Postapka:

// Korisnikot vnesuva cel broj.
// Funkcijata misterija broi koliko 1-ki ima vo binarnata predstava na brojot.
// Ako brojot na 1-ki e paren, funkcijata vrakja 1, a ako e neparen, vrakja 0.
// Na primer:

// Za brojot 5 (binarno 00000000000000000000000000000101), brojot na 1-ki e 2, pa rezultatot e 1 (paren).
// Za brojot 7 (binarno 00000000000000000000000000000111), brojot na 1-ki e 3, pa rezultatot e 0 (neparen).