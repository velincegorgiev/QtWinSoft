// 1. Само со користење на операторот за шифтирање да се напише функција mnoziSoStepenOdDva
//  која зема два целобројни аргументи: broj и stepen и ја пресметува следната вредност:
// broj * 2^stepen;

#include <stdio.h>

int mnoziSoStepenOdDva(int broj, int stepen) {
    return broj << stepen;
}

int main() {
    int broj, stepen;
    printf("vnesete broj: ");
    scanf("%d", &broj);
    printf("vnesete stepen: ");
    scanf("%d", &stepen);
    int rezultat = mnoziSoStepenOdDva(broj, stepen);
    printf("rezultatot na %d * 2^%d e: %d\n", broj, stepen, rezultat);

    return 0;
}
