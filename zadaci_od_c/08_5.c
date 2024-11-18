// 5.Да се напише програма која симулира селекциско сортирање. Селекциското сортирање го бара најмалиот
//  елемент во низата и го заменува со првиот елемент. Сега, на прво место сигурно ни се наоѓа најмалиот 
//  елемент во низата. Потоа, во остатокот од низата, од вториот до n-тиот елемент, повторно го бараме 
//  новиот најмал елемент и му ја заменуваме вредноста со вториот елемент од низата итн. Ова сортирање има 
//  слични процесирачки капацитети како сортирање со методот на меурче.
// а) Да се напише итеративна верзија на функцијата selekcija која го врши селекциското сортирање.
// б) Да се напише рекурзивна верзија на селекциското сортирање.
// в) Да се одговори зошто процесирачките капацитети на ова сортирање се слични како оние со методот на меурче.

#include <stdio.h>

void selekcijaIterativno(int niza[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (niza[j] < niza[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            temp = niza[i];
            niza[i] = niza[minIdx];
            niza[minIdx] = temp;
        }
    }
}
void selekcijaRekurzivno(int niza[], int n, int i) {
    if (i >= n - 1) {
        return; 
    }
    int minIdx = i;
    for (int j = i + 1; j < n; j++) {
        if (niza[j] < niza[minIdx]) {
            minIdx = j;
        }
    }
    if (minIdx != i) {
        int temp = niza[i];
        niza[i] = niza[minIdx];
        niza[minIdx] = temp;
    }
    selekcijaRekurzivno(niza, n, i + 1);
}
void printajNiza(int niza[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", niza[i]);
    }
    printf("\n");
}

int main() {
    int izbor, niza[] = {64, 25, 12, 22, 11};
    int n = sizeof(niza) / sizeof(niza[0]);

    printf("Pred sortiranje: ");
    printajNiza(niza, n);
    printf("Izberi verzija na selekcisko sortiranje:\n");
    printf("1. Iterativno\n");
    printf("2. Rekurzivno\n");
    printf("Vnesi izbor (1 ili 2): ");
    scanf("%d", &izbor);
    if (izbor == 1) {
        selekcijaIterativno(niza, n);
        printf("Po sortiranje (iterativno): ");
    } else if (izbor == 2) {
        selekcijaRekurzivno(niza, n, 0);
        printf("Po sortiranje (rekurzivno): ");
    } else {
        printf("Nevaliden izbor!\n");
        return 1;
    }

    printajNiza(niza, n);
    return 0;
}

// I selekcijsko sortiranje i sortiranje so meurche imaat ista vremepocesna slozenost,
//  odnosno O(n²) vo najloshiot sluchaj, i zatoa nivnite procesirachki kapaciteti (ili "vreme na izvrshuvanje") 
//  se slicni. Ova e poradi nekoliko slicnosti vo nachinot na koi rabotat ovie dva algoritma.