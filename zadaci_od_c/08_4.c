// 4.Да се напише програма која во главната функција внесува број на редици и колони
//  на дводимензионална матрица. Во функцијата vnesiMatrica внесува елементи,
//   а преку функцијата pechatiMatrica ги печати елементите во табеларна форма.
// а) Да се напишат итеративни верзии на двете функции.
// б) Да се напишат рекурзивни верзии на двете функции.

#include <stdio.h>

void vnesiMatricaIterativno(int matrica[][10], int redici, int koloni) {
    for (int i = 0; i < redici; i++) {
        for (int j = 0; j < koloni; j++) {
            printf("Vnesi element za matrica[%d][%d]: ", i, j);
            scanf("%d", &matrica[i][j]);
        }
    }
}

void vnesiMatricaRekurzivno(int matrica[][10], int redici, int koloni, int i, int j) {
    if (i >= redici) {
        return;
    }

    if (j >= koloni) {
        vnesiMatricaRekurzivno(matrica, redici, koloni, i + 1, 0);
        return;
    }

    printf("Vnesi element za matrica[%d][%d]: ", i, j);
    scanf("%d", &matrica[i][j]);

    vnesiMatricaRekurzivno(matrica, redici, koloni, i, j + 1);
}

void pechatiMatricaIterativno(int matrica[][10], int redici, int koloni) {
    for (int i = 0; i < redici; i++) {
        for (int j = 0; j < koloni; j++) {
            printf("%d ", matrica[i][j]);
        }
        printf("\n");
    }
}

void pechatiMatricaRekurzivno(int matrica[][10], int redici, int koloni, int i, int j) {
    if (i >= redici) {
        return;
    }

    if (j >= koloni) {
        printf("\n");
        pechatiMatricaRekurzivno(matrica, redici, koloni, i + 1, 0); 
        return;
    }

    printf("%d ", matrica[i][j]);
    pechatiMatricaRekurzivno(matrica, redici, koloni, i, j + 1);
}

int main() {
    int redici, koloni;
    int izbor;
    printf("Vnesi broj na redici: ");
    scanf("%d", &redici);
    printf("Vnesi broj na koloni: ");
    scanf("%d", &koloni);
    int matrica[10][10];
    printf("Izberi verzija za vnesuvanje i pechatenje na matricata:\n");
    printf("1. Iterativno\n");
    printf("2. Rekurzivno\n");
    printf("Vnesi izbor (1 ili 2): ");
    scanf("%d", &izbor);

    if (izbor == 1) {
        vnesiMatricaIterativno(matrica, redici, koloni);
        printf("Matrica (iterativno):\n");
        pechatiMatricaIterativno(matrica, redici, koloni);
    } else if (izbor == 2) {
        vnesiMatricaRekurzivno(matrica, redici, koloni, 0, 0);
        printf("Matrica (rekurzivno):\n");
        pechatiMatricaRekurzivno(matrica, redici, koloni, 0, 0);
    } else {
        printf("Nevaliden izbor!\n");
    }

    return 0;
}

