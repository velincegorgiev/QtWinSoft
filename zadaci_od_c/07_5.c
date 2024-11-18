// 5.Напиши итеративна верзија на функцијата за фибоначиеви броеви.

#include <stdio.h>
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }  
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("fibonaceviot broj na nizata %d e: %d\n", n, fibonacci(n));
    return 0;
}

