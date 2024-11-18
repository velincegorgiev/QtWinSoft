// 3. Обидете се со спецификаторот за конверзија %d да испечатите букви на следниот начин:
// printf(“%d”, ‘A’) /* karakteri se koristat vo edinecni navodnici */
// Што се случува кога се печатат следните карактери: b  c  0  1  2  $  *  +  / и празно место?

#include <stdio.h>

int main()
{
    printf("%d ",'A');
    // se pecati 65 zatoa sto bukvata A se pretvara vo ASCII kod kade A ima vrednost 65 
    printf("%d %d %d %d %d %d %d %d %d %d ",'b','c','0','1','2','$','*','+','/',' ');
    //ke se ispecatat vrednostite 98 99 48 49 50 36 42 43 47 32 
    //98-'b' 99-'c' 48-'0' 49-'1' 50-'2' 36-'$' 42-'*' 43-'+' 47-'/' 32-' ' 
    //ovie vrednosti se pecatat poradi toa sto se zemaat ASCII kodovite na 'b','c','0','1','2','$','*','+','/',' '
}