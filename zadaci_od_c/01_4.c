// 4. Напиши програм кој вчитува три цели броја и пресметува нивна целобројна средна вредност, сума и производ.

#include <stdio.h>

int main() {
    int a, b, c;
    int suma, proizvod, srednaVrednost;
    scanf("%d %d %d", &a, &b, &c);
    suma = a + b + c;
    proizvod = a * b * c;
    srednaVrednost = suma / 3;
    printf("suma: %d\n", suma);
    printf("proizvod: %d\n", proizvod);
    printf("celobrojna sredna vrednost: %d\n", srednaVrednost);

    return 0;
}
