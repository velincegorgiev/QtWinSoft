// 4.Напиши програма која за внесен цел број кој може да е најмногу  
//четири цифрен го испечатува неговиот еквивалент во римски броеви.

#include <stdio.h>

void convertToRoman(int num) {
    if (num >= 1000) { printf("M"); num -= 1000; }
    if (num >= 900) { printf("CM"); num -= 900; }
    if (num >= 500) { printf("D"); num -= 500; }
    if (num >= 400) { printf("CD"); num -= 400; }
    if (num >= 100) { printf("C"); num -= 100; }
    if (num >= 90) { printf("XC"); num -= 90; }
    if (num >= 50) { printf("L"); num -= 50; }
    if (num >= 40) { printf("XL"); num -= 40; }
    if (num >= 10) { printf("X"); num -= 10; }
    if (num >= 9) { printf("IX"); num -= 9; }
    if (num >= 5) { printf("V"); num -= 5; }
    if (num >= 4) { printf("IV"); num -= 4; }
    if (num >= 1) { printf("I"); num -= 1; } 
    printf("\n");
}

int main() {
    int num;
    printf("vnesi cel broj (do 9999): ");
    scanf("%d", &num);
    if (num < 1 || num > 9999) {
        printf("vneseniot broj e nadvor od dadeniot opseg.\n");
    } else {
        convertToRoman(num);
    }

    return 0;
}

