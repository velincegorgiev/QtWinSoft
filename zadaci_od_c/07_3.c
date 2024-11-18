// 3.Напиши програма која на функцијата obratno и доделува цел број.
//  Оваа функција го враќа бројот напишан со обратни цифри, 
//  т.е. ако сме ја повикале функцијата со параметарот 1243, треба да врати 3421.

#include <stdio.h>

int obratno(int broj) {
    int obrnatiBroj = 0;
    while (broj != 0) {
        int poslednaCifra = broj % 10; 
        obrnatiBroj = obrnatiBroj * 10 + poslednaCifra; 
        broj = broj / 10; 
    }
    
    return obrnatiBroj;
}

int main() {
    int broj;
    scanf("%d", &broj);
    printf("%d", obratno(broj));
    
    return 0;
}
