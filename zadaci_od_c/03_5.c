// 5. Напиши програма која внесува радиус на круг и испечатува негова плоштина и периметар. За вредност на пи да се земе 3.14.

#include <stdio.h>

int main() {
    float r, ploshtina, perimetar;
    const float PI = 3.14;
    scanf("%f", &r);
    ploshtina = PI * r * r;  
    perimetar = 2 * PI * r;  
    printf("Ploshtina na krugot e: %.2f\n", ploshtina);
    printf("Perimetar na krugot e: %.2f\n", perimetar);
    return 0;
}

