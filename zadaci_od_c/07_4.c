// 4.Напиши програма во која дефинираш функција nzd за пресметување на најголемиот заеднички делител на два броја.

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

