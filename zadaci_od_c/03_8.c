// 8. Напиши 4 начини за да ја зголемиш вредноста на променливата x за 1.

#include <stdio.h>

int main() {
    int x = 0;
    x++;
    printf("prv nacin (x++): %d\n", x);
    x += 1;
    printf("vtor nacin (x += 1): %d\n", x); 
    x = x + 1;
    printf("tret nacin (x = x + 1): %d\n", x); 
    ++x;
    printf("cetvrt nacin (++x): %d\n", x);

    return 0;
}

