// Една стоковна куќа продава 5 производи чии цени се дадени во долната табела
// Производ број	Цена
//             1	50.5
//             2	45.6
//             3	32.8
//             4	65.3
//             5	20.0
// Да се напише програм кој чита серија од парови броеви за:
// а) број на производ
// б) количина продадена во текот на денот
// Програмот треба да ја користи switch наредбата за да ја одреди цената за секој  производ.
// Програмот треба да ја пресмета и испечати вкупната продадена вредност за секој од производите посебно, 
//како и вкупната сума за сите производи продадени во текот на денот.

#include <stdio.h>

int main() {
    int proizvod, kolicina;
    double cena, suma = 0;
    printf("proizvodi i ceni:\n");
    printf("1 - 50.5\n");
    printf("2 - 45.6\n");
    printf("3 - 32.8\n");
    printf("4 - 65.3\n");
    printf("5 - 20.0\n");
    while (1) {
        printf("vnesi broj za proizvodi ");
        scanf("%d", &proizvod);
        if (proizvod == 0) {
            break;
        }
        printf("vnesi kolicina na proizvod %d: ", proizvod);
        scanf("%d", &kolicina);
        switch (proizvod) {
            case 1:
                cena = 50.5;
                break;
            case 2:
                cena = 45.6;
                break;
            case 3:
                cena = 32.8;
                break;
            case 4:
                cena = 65.3;
                break;
            case 5:
                cena = 20.0;
                break;
            default:
                printf("nevaliden broj na proizvod!\n");
                continue;
        }
        double vrednost = cena * kolicina;
        suma += vrednost;
        printf("proizvod %d, kolicina: %d, cena: %.2f, vrednost: %.2f\n", proizvod, kolicina, cena, vrednost);
    }
    printf("\nvkupnata suma za site prodadeni proizvodi e: %.2f\n", suma);
    return 0;
}


