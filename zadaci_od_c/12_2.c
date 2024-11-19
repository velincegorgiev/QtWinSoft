// 2. Напиши програм кој го превртува редоследот на битовите на целобројна unsigned вредност.
//  Програмот треба да вчита вредност од корисникот и да ја повика функцијата prevtriBitovi 
//  за да се испечатат битовите во обратен редослед. Вредностите на битовите да се испечатат и пред и после превртувањето.

#include <stdio.h>

void prikaziBitovi(unsigned int broj) {
    for (int i = sizeof(broj) * 8 - 1; i >= 0; i--) {
        unsigned int bit = (broj >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

unsigned int prevtriBitovi(unsigned int broj) {
    unsigned int obratno = 0;
    int brojBitovi = sizeof(broj) * 8;
    for (int i = 0; i < brojBitovi; i++) {
        obratno |= ((broj >> i) & 1) << (brojBitovi - 1 - i);
    }
    return obratno;
}

int main() {
    unsigned int broj;
    printf("vnesete unsigned celobrojna vrednost: ");
    scanf("%u", &broj);
    printf("bitovi pred prevrtuvanje: ");
    prikaziBitovi(broj);
    unsigned int obratno = prevtriBitovi(broj);
    printf("bitovi po prevrtuvanje: ");
    prikaziBitovi(obratno);

    return 0;
}

