// 6.Напиши рекурзивна верзија на функцијата за пресметување најголем заеднички делител.

#include <stdio.h>

int nzd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return nzd(b, a % b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int rezultat=nzd(a, b);

    printf("nzd e: %d\n", nzd(a, b));
    
    return 0;
}

