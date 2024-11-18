// 3.Да се најде спротивен број на природниот број n. 
// (Тоа е природниот број што ги има истите цифри со n, напишани во спротивен редослед.)

#include <stdio.h>

int main() {
    int n, reversed = 0;
    printf("Vnesi priroden broj n: ");
    scanf("%d", &n);
    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }
    printf("Sprotiot broj na n e: %d\n", reversed);

    return 0;
}
