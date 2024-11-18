// 1.Да се најде обиколката и плоштината на правилен n-аголник.

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double a;
    double pi = 3.14159;
    printf("Vnesi broj na strani (n): ");
    scanf("%d", &n);
    printf("Vnesi dolzina na stranata (a): ");
    scanf("%lf", &a);
    double P = n * a;
    double S = (n * a * a) / (4 * tan(pi / n));

    printf("Obikolka na pravilniot %d-agolnik: %.2lf\n", n, P);
    printf("Ploshtina na pravilniot %d-agolnik: %.2lf\n", n, S);

    return 0;
}


