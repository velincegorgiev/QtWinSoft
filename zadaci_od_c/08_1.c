// 1.Напиши програм кој вчитува вредности за температури за секој ден 
// од месецот и наоѓа средна месечна температура. Да се земе предвид дека
//  различни месеци имаат различен број на денови.

#include <stdio.h>

int main() {
    int mesec, i, broj_dnevi;
    float suma_temperaturi = 0.0, temperatura, sredna_temperatura;
    printf("Vnesi mesec (1-12): ");
    scanf("%d", &mesec);
    switch (mesec) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            broj_dnevi = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            broj_dnevi = 30;
            break;
        case 2:
            printf("Vnesi godina: ");
            int godina;
            scanf("%d", &godina);
            if ((godina % 4 == 0 && godina % 100 != 0) || (godina % 400 == 0)) {
                broj_dnevi = 29;
            } else {
                broj_dnevi = 28;
            }
            break;
        default:
            printf("nevaliden mesec!\n");
            return 1;
    }
    float temperatures[broj_dnevi];
    for (i = 0; i < broj_dnevi; i++) {
        printf("Vnesi temperatura za den %d: ", i + 1);
        scanf("%f", &temperatura);
        temperatures[i] = temperatura; 
        suma_temperaturi += temperatura;
    }

    sredna_temperatura = suma_temperaturi / broj_dnevi;

    printf("Sredna mesecna temperatura za mesec %d e: %.2f\n", mesec, sredna_temperatura);

    return 0;
}

